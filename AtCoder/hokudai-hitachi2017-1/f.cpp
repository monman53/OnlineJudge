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

double MAX_T = 9.9;
double ALPHA = 0.995;
double T     = 1.0;
double PROB  = 1.0;
int DIFF     = 9;

double sec = 0.0;

bool full = true;
bool sparse = true;

int n, ne, m, me;
int gh, geh;
int g[500][500], ge[3600][3600];
vector<vector<int>> gl;
vector<vector<int>> gel;
//int dst[3600][3600];
int u[20000], v[20000];
int w[500][500];
int wc[500][500];
int w_sum;

inline double exp_(double x) {
    //return 1.0+x+x*x*0.5+x*x*x*(1.0/6.0);
    return 1.0+x*(1.0+x*0.5);
}

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123; 
    uint32_t t;

    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

struct State { // {{{
    vector<int> f;
    vector<int> fr;
    int score;
    State() {
        f.resize(n);
        fr.resize(ne, -1);
        int pad = (geh - gh)/2;
        for(int i=0;i<n;i++){
            f[i] = (i/gh+pad)*geh + i%gh + pad;
        }
        for(int i=0;i<n;i++){
            fr[f[i]] = i;
        }
        score = score_();
    }
    inline double score_() {
        int ret = 0;
        for(int i=0;i<m;i++){
            int uu = f[u[i]];
            int vv = f[v[i]];
            if(ge[uu][vv] == 1){
                ret += w[u[i]][v[i]];
            }
        }
        return ret;
    }
    inline void print() { // {{{
        string s[60][60];
        for(int i=0;i<geh;i++){
            for(int j=0;j<geh;j++){
                s[i][j] = "--";
            }
        }
        for(int i=0;i<n;i++){
            s[f[i]/geh][f[i]%geh] = "##";
        }
        //cout << "\033[2J" << endl;
        for(int i=0;i<geh;i++){
            for(int j=0;j<geh;j++){
                cout << s[i][j];
            }
            cout << endl;
        }
    }// }}}
    inline int swap_s(const int &i, const int &j) {
        int diff = 0;
        for(const int &k : gel[f[i]]){
            const int kr = fr[k];
            if(kr == -1) continue;
            diff -= w[i][kr];
            diff += w[j][kr];
        }
        for(const int &k : gel[f[j]]){
            const int kr = fr[k];
            if(kr == -1) continue;
            diff -= w[j][kr];
            diff += w[i][kr];
        }
        if(ge[f[i]][f[j]]) diff += 2*w[i][j];
        return diff;

        //if(score != score_()) cout << "!!!!!" << endl;
    }
    inline void swap(const int &i, const int &j) {
        std::swap(f[i], f[j]);
        std::swap(fr[f[i]], fr[f[j]]);
    }
}; // }}}

int main() {
    std::ios::sync_with_stdio(false);

    clock_t start = clock();

    memset(g, 0, sizeof(g));
    memset(ge, 0, sizeof(ge));
    memset(w, 0, sizeof(w));

    //----------------
    // input
    //----------------
    // {{{
    
    // G
    cin >> n >> m;
    for(int i=0;i*i<n;i++){
        gh = i;
    }
    gh++;
    gl.resize(n);
    for(int i=0;i<m;i++){
        int uu, vv, ww;cin >> uu >> vv >> ww;uu--;vv--;
        u[i] = uu;v[i] = vv;
        g[uu][vv] = g[vv][uu] = 1;
        gl[uu].push_back(vv);
        gl[vv].push_back(uu);
        w[uu][vv] = w[vv][uu] = ww;
    }
    for(int i=0;i<n;i++){
        if(int(gl[i].size()) != n-1){
            full = false;
        }
        if(int(gl[i].size()) > 8){
            sparse = false;
        }
    }
    if(full) DIFF = 8;

    // GE
    cin >> ne >> me;
    gel.resize(ne);
    for(int i=0;i<me;i++){
        int a, b;cin >> a >> b;a--;b--;
        ge[a][b] = ge[b][a] = 1;
        gel[a].push_back(b);
        gel[b].push_back(a);
    }
    for(int i=0;i*i<=ne;i++) geh = i;
    // }}}

    //----------------
    // calc
    //----------------
    // {{{
    vector<int> ff;

    // params

    // init
    int count = 0;
    clock_t end = clock();
    State state = State();
    State best = state;
    PROB = exp_(-1/T);

    // routine
    while(true){
        if(count%100000 == 0){
            end = clock();
            sec = double(end - start)/CLOCKS_PER_SEC;
            T   = pow(ALPHA, sec/MAX_T);
            if(full){
                PROB = 0.4-0.4*(sec/MAX_T);
            }else if(sparse){
                PROB = 0.3-0.3*(sec/MAX_T);
            }else{
                PROB= exp_(-1/T);
            }
            if(sec > MAX_T) break;
            //best.print();
            //cout << best.score_() << " " << best.score << endl;
            //cout << best.score << endl;
        }
        count++;

        const int i = xor128()%n;
        const int j = xor128()%n;
        const int diff = state.swap_s(i, j);

        if(diff >= 0){
            if(state.score + diff > best.score){
                best = state;
            }
            state.score += diff;
            state.swap(i, j);
        }else if(diff > -DIFF){
            if(double(xor128())/UINT32_MAX <= PROB){
                state.score += diff;
                state.swap(i, j);
            }
        }
    }
    // }}}

    while(true){
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                const int diff = best.swap_s(i, j);
                if(diff > 0){
                    //cout << "!!!!!!" << b-a << endl;
                    flag = true;
                    best.score += flag;
                    best.swap(i, j);
                }
            }
        }
        end = clock();
        sec = double(end - start)/CLOCKS_PER_SEC;
        if(sec > MAX_T+0.05) break;
        if(!flag) break;
    }

    //----------------
    // output
    //----------------
    for(int i=0;i<n;i++){
        cout << i+1 << " " << best.f[i]+1 << endl;
    }

    return 0;
}
