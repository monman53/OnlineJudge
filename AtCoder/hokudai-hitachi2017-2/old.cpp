#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

double MAX_SEC = 9.95;
double sec = 0.0;

double UINT32_MAX_R = (double)1.0/UINT32_MAX;

int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m;
int ne, me;
int he;
int u[20000], v[20000];
int g[500][500];
int ge[3600][3600];
vector<vector<int>> gl, gel;

struct State { // {{{
    int t[60][60];
    State() { // {{{
        memset(t, -1, sizeof(t));
        int kita[60][60];memset(kita, 0, sizeof(kita));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {he/2, he/2}});
        int k = 0;
        while(k < n){
            auto c = pq.top();pq.pop();
            int i = c.second.first;
            int j = c.second.second;
            if(kita[i][j]) continue;
            kita[i][j] = 1;
            t[i][j] = k;
            k++;
            for(int l=0;l<8;l++){
                int ni = i + di[l];
                int nj = j + dj[l];
                if(ni >= 0 && ni < he && nj >= 0 && nj < he){
                    int ddi = ni - he/2;
                    int ddj = nj - he/2;
                    pq.push({-(ddi*ddi+ddj*ddj), {ni, nj}});
                }
            }
        }
        score = score_();
    }// }}}
    int c[500][500];
    int c_sum;
    int c_cnt[500];
    int score;
    inline int score_() { // {{{
        // 1 5000
        int ret = 5000;

        // 2 100
        memset(c, 0, sizeof(c));
        for(int i=0;i<he;i++){
            for(int j=0;j<he;j++){
                if(t[i][j] == -1) continue;
                for(int k=0;k<8;k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni >= 0 && ni < he && nj >= 0 && nj < he){
                        if(t[ni][nj] == -1) continue;
                        c[t[i][j]][t[ni][nj]]++;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(c[i][j] && g[i][j]){
                    ret += 100;
                }
            }
        }

        // 3 100000
        int c_sum = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(c[i][j]) c_sum++;
            }
        }
        if(c_sum == m) ret += 100000;

        // 4 penalty
        int c_cnt[500];memset(c_cnt, 0, sizeof(c_cnt));
        for(int i=0;i<he;i++){
            for(int j=0;j<he;j++){
                if(t[i][j] < 0) continue;
                c_cnt[t[i][j]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(c_cnt[i]){
                ret -= c_cnt[i]-1;
            }
        }

        return ret;
    }// }}}
    inline void print() { // {{{
        vector<vector<int>> ans(n);
        for(int i=0;i<he;i++){
            for(int j=0;j<he;j++){
                if(t[i][j] < 0) continue;
                ans[t[i][j]].push_back(i*he+j);
            }
        }
        for(int i=0;i<n;i++){
            cout << ans[i].size();
            for(int j : ans[i]){
                cout << " " << j+1;
            }
            cout << endl;
        }
    }// }}}
    inline void swap(int u, int v) { // {{{
        int ui = u/he;
        int uj = u%he;
        int vi = v/he;
        int vj = v%he;
        std::swap(t[ui][uj], t[vi][vj]);
    }// }}}
};
// }}}

inline uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123; 
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main() {
    std::ios::sync_with_stdio(false);
    clock_t start = clock();

    //----------------
    // input
    //----------------
    // {{{

    // g
    cin >> n >> m;
    gl.resize(n);
    for(int i=0;i<m;i++){
        cin >> u[i] >> v[i];u[i]--;v[i]--;
        gl[u[i]].push_back(v[i]);
        gl[v[i]].push_back(u[i]);
        g[u[i]][v[i]] = g[v[i]][u[i]] = 1;
    }

    // ge
    cin >> ne >> me;
    gel.resize(ne);
    memset(ge, 0, sizeof(ge));
    for(int i=0;i<me;i++){
        int a, b;cin >> a >> b;a--;b--;
        gel[a].push_back(b);
        gel[b].push_back(a);
        ge[a][b] = ge[b][a] = 1;
    }
    for(int j=0;j*j<=ne;j++){
        he = j;
    }

    // }}}

    //----------------
    // simulated annealing
    //----------------
    // {{{

    State state;
    State best = state;
    State next;
    int cnt = 0;
    int cnt_msk = (1 << 5) -1;

    while(true){
        if(!(cnt&cnt_msk)){
            clock_t end = clock();
            sec = double(end-start)/CLOCKS_PER_SEC;
            if(sec > MAX_SEC) break;

            cout << state.score_() << endl;
        }
        cnt++;
        next = state;
        next.swap(xor128()%ne, xor128()%ne);
        if(next.score_() > state.score_()){
            state = next;
            if(state.score_() > best.score_()){
                best = state;
            }
        }
    }

    // }}}

    //----------------
    // output
    //----------------
    // {{{

    best.print();

    // }}}
    return 0;
}
