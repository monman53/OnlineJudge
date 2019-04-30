// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

template<class T>
struct GF {
    struct EF {
        int to;
        T cap;
        int rev;
    };

    int n;
    vector<vector<EF>> e;

    GF() {}
    GF(int n) {
        this->n = n;
        e.resize(n);
    }

    void add(int from, int to, T cap) {
        e[from].push_back({to, cap, int(e[to].size())});
        e[to].push_back({from, 0, int(e[from].size()-1)});
    }
};


// 最大流 (Ford-Fulkerson) {{{
// O(FE)
// verified AOJ GRL_6_A
template<class T>
struct MF {
    GF<T> g;
    vector<bool> visited;

    MF() {}
    MF(const GF<T> &g) {
        this->g = g;
        visited.resize(g.n, false);
    };

    T dfs(int v, int t, T f) {
        if(v == t) return f;
        visited[v] = true;
        for(auto &e : g.e[v]){
            if(!visited[e.to] && e.cap > 0){
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g.e[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T query(int from, int to) {
        T flow = 0;
        while(true){
            fill(visited.begin(), visited.end(), false);
            T f = dfs(from, to, INF);
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
};//}}}

int main() {
    int v, e;cin >> v >> e;
    GF<int> g(v);
    for(int i=0;i<e;i++){
        int u, v, c;cin >> u >> v >> c;
        g.add(u, v, c);
    }
    MF<int> mf(g);
    cout << mf.query(0, v-1) << endl;
    return 0;
}
