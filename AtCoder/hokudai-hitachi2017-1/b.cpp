// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

random_device rnd;

int n, ne, m, me;
int g[500][500], ge[3600][3600];
vector<vector<int>> gel;
int dst[3600][3600];
int w[500][500];
int w_sum;
int u[20000], v[20000];

inline double eval(const vector<int> &f) {
    double ret = 0;
    int dst_sum = 0;
    for(int i=0;i<m;i++){
        int uu = f[u[i]];
        int vv = f[v[i]];
        if(dst[uu][vv] == 1){
            ret += w[u[i]][v[i]];
        }
        dst_sum += dst[uu][vv];
    }
    return 1.0-(ret/w_sum)*(m/double(dst_sum));
    //return 1.0-(ret/w_sum);
}

inline double score(const vector<int> &f) {
    double ret = 0;
    for(int i=0;i<m;i++){
        int uu = f[u[i]];
        int vv = f[v[i]];
        if(dst[uu][vv] == 1){
            ret += w[u[i]][v[i]];
        }
    }
    return ret;
}

inline vector<int> neighbour(const vector<int> f) {
    vector<int> ret = f;

    //for(int i=0;i<1;i++){
        int s = rnd()%n;

        int size = gel[f[s]].size();

        int t = rnd()%ne;
        if(rnd()%5 == 0){
            t = gel[f[s]][rnd()%size];
        }


        bool flag = false;
        int id = 0;
        for(int j=0;j<n;j++){
            if(ret[j] == t){
                flag = true;
                id = j;
                break;
            }
        }
        if(flag){
            swap(ret[s], ret[id]);
        }else{
            ret[s] = t;
        }
    //}
    return ret;
}


int main() {
    std::ios::sync_with_stdio(false);

    clock_t start = clock();

    mt19937 engine(rnd());

    memset(g, 0, sizeof(g));
    memset(ge, 0, sizeof(ge));
    memset(w, 0, sizeof(w));

    //----------------
    // input
    //----------------
    
    // G
    cin >> n >> m;
    w_sum = 0;
    for(int i=0;i<m;i++){
        int uu, vv, ww;cin >> uu >> vv >> ww;uu--;vv--;
        u[i] = uu;v[i] = vv;
        g[uu][vv] = g[vv][uu] = 1;
        w[uu][vv] = w[vv][uu] = ww;
        w_sum += ww;
    }

    // GE
    cin >> ne >> me;
    gel.resize(ne);
    for(int i=0;i<me;i++){
        int a, b;cin >> a >> b;a--;b--;
        ge[a][b] = ge[b][a] = 1;
        gel[a].push_back(b);
        gel[b].push_back(a);
    }
    int h = 0;
    int w = 0;
    for(int i=0;i*i<=ne;i++) h = i;
    w = h;
    for(int i=0;i<h*w;i++){
        for(int j=0;j<h*w;j++){
            int ix = i%w;
            int iy = i/w;
            int jx = j%w;
            int jy = j/w;
            dst[i][j] = abs(abs(ix-jx) - abs(iy-jy)) + min(abs(ix-jx), abs(iy-jy));
        }
    }

    //----------------
    // calc
    //----------------
    vector<int> ff;

    // params
    int LENGTH = 6;
    int TOP    = 2;

    // init
    vector<int> f(n);
    for(int i=0;i<n;i++) f[i] = i;
    vector<pair<double, vector<int>>> fs(LENGTH*2);
    for(int i=0;i<LENGTH*2;i++){
        shuffle(f.begin(), f.end(), engine);
        fs[i] = {eval(f), f};
    }

    // routine
    clock_t end = clock();
    while(true){
        for(int i=0;i<LENGTH;i++){
            ff = neighbour(fs[i%TOP].second);
            fs[LENGTH+i] = {eval(ff), ff};
        }

        sort(fs.begin(), fs.end());

        end = clock();
        double sec = double(end - start)/CLOCKS_PER_SEC;

        if(sec > 9.8) break;
        //cout << score(fs[0].second) << endl;
    }

    //----------------
    // output
    //----------------
    vector<int> ans = fs[0].second;
    for(int i=0;i<n;i++){
        cout << i+1 << " " << ans[i]+1 << endl;
    }

    return 0;
}
