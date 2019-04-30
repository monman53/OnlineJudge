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
mt19937 engine;

double MAX_T = 1009.9;
double sec = 0.0;

int n, ne, m, me;
int g[500][500], ge[3600][3600];
vector<vector<int>> gel;
int dst[3600][3600];
int w[500][500];
int w_sum;
int u[20000], v[20000];
int h = 0;

struct State { // {{{
    vector<int> f;
    map<int, int> fr;
    int score;
    double e;
    State() {
        this->init();
    }
    inline void init() {
        f.clear();
        f.resize(n);
        int gh;
        for(gh=0;gh*gh<=n;gh++){}
        gh--;
        for(int i=0;i<n;i++){
            f[i] = i/gh*h + i%gh;
        }
        shuffle(f.begin(), f.end(), engine);
        for(int i=0;i<n;i++){
            fr[f[i]] = i;
        }
        //e = eval();
        score = score_();
        eval();
    }
    inline void eval() {
        double weight = double(score)/w_sum;
        e = 1.0-weight;
    }
    inline void swap(int i, int j) {
        for(int k : gel[f[i]]){
            if(fr.find(k) != fr.end()){
                score -= w[i][fr[k]];
            }
        }
        for(int k : gel[f[j]]){
            if(fr.find(k) != fr.end()){
                score -= w[j][fr[k]];
            }
        }

        std::swap(f[i], f[j]);
        std::swap(fr[f[i]], fr[f[j]]);
        //fr[f[i]] = j;fr[f[j]] = i;

        for(int k : gel[f[i]]){
            if(fr.find(k) != fr.end()){
                score += w[i][fr[k]];
            }
        }
        for(int k : gel[f[j]]){
            if(fr.find(k) != fr.end()){
                score += w[j][fr[k]];
            }
        }
        eval();
    }
    inline int score_() {
        int ret = 0;
        for(int i=0;i<m;i++){
            int uu = f[u[i]];
            int vv = f[v[i]];
            if(dst[uu][vv] == 1){
                ret += w[u[i]][v[i]];
            }
        }
        return ret;
    }
    inline void print() {
        char c[60][60];
        for(int i=0;i<h;i++){
            for(int j=0;j<h;j++){
                c[i][j] = '-';
            }
        }
        for(int i=0;i<n;i++){
            c[f[i]/h][f[i]%h] = '#';
        }
        //cout << "\033[2J" << endl;
        for(int i=0;i<h;i++){
            for(int j=0;j<h;j++){
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    bool operator<(const State &right) const {
        return e < right.e;
    }
}; // }}}


int main() {
    std::ios::sync_with_stdio(false);

    clock_t start = clock();

    engine = mt19937(rnd());

    memset(g, 0, sizeof(g));
    memset(ge, 0, sizeof(ge));
    memset(w, 0, sizeof(w));

    //----------------
    // input
    //----------------
    // {{{
    
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
    for(int i=0;i*i<=ne;i++) h = i;
    for(int i=0;i<ne;i++){
        for(int j=0;j<ne;j++){
            int ix = i%h;
            int iy = i/h;
            int jx = j%h;
            int jy = j/h;
            dst[i][j] = abs(abs(ix-jx) - abs(iy-jy)) + min(abs(ix-jx), abs(iy-jy));
        }
    }
    // }}}

    //----------------
    // calc
    //----------------
    vector<int> ff;

    // params
    const int LENGTH = 1;

    // init
    vector<State> states;
    states.push_back(State());
    
    for(int i=0;i<LENGTH;i++){
        states.push_back(State());
    }

    // routine
    clock_t end = clock();
    for(int count=0;;count++){
        //sort(states.begin(), states.end(), [](State s1, State s2){return s1.e < s2.e;});
        sort(states.begin(), states.end());

        states.resize(LENGTH);

        cout << states[0].score << endl;

        for(int i=0;i<LENGTH;i++){
            //for(int j=0;j<n;j++){
            int j = rnd()%n;
                for(int k=0;k<n;k++){
                    if(j == k) continue;
                    State ss = states[i];
                    ss.swap(j, k);
                    if(ss.e > states[i].e) continue;
                    states.push_back(ss);
                }
            //}
        }

        //if(count%1 == 0){
            end = clock();
            sec = double(end - start)/CLOCKS_PER_SEC;
            if(sec > MAX_T) break;
        //}
    }

    //----------------
    // output
    //----------------
    //vector<int> ans = fs[0].f;
    auto ans = states[0];
    for(int i=0;i<n;i++){
        cout << i+1 << " " << ans.f[i]+1 << endl;
    }

    return 0;
}
