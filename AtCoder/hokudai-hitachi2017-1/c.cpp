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
uniform_real_distribution<> dist;

int n, ne, m, me;
int g[500][500], ge[3600][3600];
int dst[3600][3600];
int w[500][500];
int w_sum;
int u[20000], v[20000];
int h = 0;

struct State { // {{{
    vector<int> f;
    double e;
    State() {
        this->init();
    }
    inline void init() {
        f.clear();
        f.resize(n);
        int gh = 0;
        for(int i=0;i*i<=n;i++){
            gh = i;
        }
        for(int i=0;i<n;i++){
            f[i] = i/gh*h + i%gh;
        }
        shuffle(f.begin(), f.end(), engine);
        e = eval();
    }
    inline double eval() {
        double ret = 0;
        //int dst_sum = 0;
        for(int i=0;i<m;i++){
            int uu = f[u[i]];
            int vv = f[v[i]];
            if(dst[uu][vv] == 1){
                ret += w[u[i]][v[i]];
            }
            //dst_sum += dst[uu][vv];
        }
        double weight = ret/w_sum;
        //double chikai = m/double(dst_sum);
        return 1.0-weight;
    }
    inline double score() {
        double ret = 0;
        for(int i=0;i<m;i++){
            int uu = f[u[i]];
            int vv = f[v[i]];
            if(dst[uu][vv] == 1){
                ret += w[u[i]][v[i]];
            }
        }
        //print();
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
    inline void next() {
        //for(int i=0;i<2;i++){
            int s = rnd()%n;
            int t = rnd()%n;
            swap(f[s], f[t]);
        //}
        e = eval();
    }
}; // }}}

inline double temperature(double r) {
    return pow(0.4, r);
}

inline double random_uniform() {
    return dist(engine);
}

inline double probability(double e1, double e2, double t) {
    if(e1 >= e2){
        return 1.0;
    }else{
        return exp((e1-e2)/t);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    clock_t start = clock();

    engine = mt19937(rnd());
    dist = uniform_real_distribution<>(0.0, 1.0);

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
    for(int i=0;i<me;i++){
        int a, b;cin >> a >> b;a--;b--;
        ge[a][b] = ge[b][a] = 1;
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

    //----------------
    // calc
    //----------------

    State state = State();
    double state_e = state.eval();

    State best_state = state;
    double best_state_e = state_e;

    while(true){
        clock_t end = clock();
        double sec = double(end-start)/CLOCKS_PER_SEC;
        if(sec > 1119.8) break;

        State next_state = best_state;next_state.next();
        double next_state_e = next_state.eval();

        if(next_state_e < best_state_e){
            best_state = next_state;
            best_state_e = next_state_e;
        }

        if(random_uniform() <= probability(state_e, next_state_e, temperature(sec/10.0))){
            state = next_state;
            state_e = next_state_e;
        }

        cout << best_state.score() << endl;
    }

    //----------------
    // output
    //----------------
    for(int i=0;i<n;i++){
        cout << i+1 << " " << best_state.f[i]+1 << endl;
    }

    return 0;
}
