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

double MAX_T = 99.9;
double ALPHA = 0.99;
double T     = 1.0;
double UINT32_MAX_R = 1.0/UINT32_MAX;

double sec = 0.0;

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

inline double probability(int s1, int s2, double t) {
    if(s1 <= s2){
        return 1.0;
    }else{
        //if(s1-s2 < 6){
        if(s1-s2 < 8){
            //-return t*0.3+0.7;
            //return exp(-t)+0.5;
            return exp_(-1/t);
            //return t*0.5 + 0.5;
        }else{
            return 0.0;
        }
    }
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
    vector<int> count;
    set<int> edge;
    int score;
    State() {
        f.resize(n);
        fr.resize(ne, -1);
        count.resize(n, 0);
        int pad = (geh - gh)/2;
        for(int i=0;i<n;i++){
            f[i] = (i/gh+pad)*geh + i%gh + pad;
        }
        shuffle(f.begin(), f.end(), engine);
        for(int i=0;i<n;i++){
            fr[f[i]] = i;
        }
        for(int i=0;i<n;i++){
            for(const int &j : gel[f[i]]) {
                if(fr[j] == -1){
                    edge.insert(j);
                }else{
                    count[i]++;
                }
            }
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
            s[f[i]/geh][f[i]%geh] = "#" + to_string(count[i]);
            //s[f[i]/geh][f[i]%geh] = "##";
        }
        for(int e : edge){
            s[e/geh][e%geh] = "ee";
        }
        //cout << "\033[2J" << endl;
        for(int i=0;i<geh;i++){
            for(int j=0;j<geh;j++){
                cout << s[i][j];
            }
            cout << endl;
        }
    }// }}}
    inline void swap(const int &i, const int &j) { // {{{
        for(const int &k : gel[f[i]]){
            const int &kr = fr[k];
            if(kr == -1) continue;
            score -= w[i][kr];
            score += w[j][kr];
        }
        for(const int &k : gel[f[j]]){
            const int &kr = fr[k];
            if(kr == -1) continue;
            score -= w[j][kr];
            score += w[i][kr];
        }
        if(ge[f[i]][f[j]]) score += 2*w[i][j];
        std::swap(f[i], f[j]);
        std::swap(fr[f[i]], fr[f[j]]);
        std::swap(count[i], count[j]);

        //if(score != score_()) cout << "!!!!!" << endl;
    } // }}}
    inline void next() {
        /*
        this->swap(xor128()%n, xor128()%n);
        */
        while(true){
            const int s = xor128()%n;
            if(count[s] < 5 && xor128()*UINT32_MAX_R < exp(-1/T)){
            //if(false){
                int m = edge.size();
                if(m == 0) continue;
 
                int tt = xor128()%m;
                int i = 0;
                for(int e : edge){
                    if(i == tt){
                        tt = e;
                        break;
                    }
                    i++;
                }
                const int t = tt;

                fr[f[s]] = -1;
                edge.insert(f[s]);
                for(const int &k : gel[f[s]]){
                    const int &kr = fr[k];
                    if(fr[k] == -1){
                        bool flag = true;
                        for(const int &l : gel[k]){
                            if(fr[l] != -1){
                                flag = false;
                            }
                        }
                        if(flag){
                            edge.erase(k);
                        }
                    }else{
                        score -= w[s][kr];
                        count[kr]--;
                    }
                }
                edge.erase(t);
                count[s] = 0;
                fr[t] = s;
                f[s] = t;
                for(const int &k : gel[t]){
                    const int &kr = fr[k];
                    if(kr != -1){
                        score += w[s][kr];
                        count[kr]++;
                        count[s]++;
                    }else{
                        edge.insert(k);
                    }
                }
            }else{
                int t = xor128()%n;
                if(s == t) continue;
                this->swap(s, t);
            }
            break;
        }
        //if(score != score_()) cout << "!!!!!" << endl;
    }
}; // }}}

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
    // {{{
    
    // G
    cin >> n >> m;
    gl.resize(n);
    for(int i=0;i*i<n;i++){
        gh = i;
    }
    gh++;
    for(int i=0;i<m;i++){
        int uu, vv, ww;cin >> uu >> vv >> ww;uu--;vv--;
        u[i] = uu;v[i] = vv;
        g[uu][vv] = g[vv][uu] = 1;
        w[uu][vv] = w[vv][uu] = ww;
        gl[uu].push_back(vv);
        gl[vv].push_back(uu);
    }
    /*
    w_sum = 0;
    for(int i=0;i<n;i++){
        vector<int> ew;
        for(int j : gl[i]){
            ew.push_back(w[i][j]);
        }
        sort(ew.begin(), ew.end());
        reverse(ew.begin(), ew.end());
        for(int j=0;j<min((int)gl[i].size(), 8);j++){
            w_sum += ew[j];
        }
    }
    */

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
    /*
    for(int i=0;i<ne;i++){
        for(int j=0;j<ne;j++){
            int ix = i%geh;
            int iy = i/geh;
            int jx = j%geh;
            int jy = j/geh;
            dst[i][j] = abs(abs(ix-jx) - abs(iy-jy)) + min(abs(ix-jx), abs(iy-jy));
        }
    }
    */
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
    State next = state;

    // routine
    while(true){
        next = state;
        next.next();
        if(next.score > best.score){
            best = next;
        }
        //if(dist(engine) <= probability(state.score, next.score, T)){
        if(xor128()*UINT32_MAX_R <= probability(state.score, next.score, T)){
            state = next;
        }
        if(count%10000 == 0){
            end = clock();
            sec = double(end - start)/CLOCKS_PER_SEC;
            T   = pow(ALPHA, sec/MAX_T);
            if(sec > MAX_T) break;
            best.print();
            //cout << best.score_() << " " << best.score << endl;
            cout << best.score << endl;
        }
        count++;
    }
    // }}}

    //----------------
    // output
    //----------------
    for(int i=0;i<n;i++){
        cout << i+1 << " " << best.f[i]+1 << endl;
    }

    return 0;
}
