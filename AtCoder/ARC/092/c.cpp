// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

// graph flow {{{
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
//}}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    inc(i, 0, n) cin >> a[i] >> b[i];
    inc(i, 0, n) cin >> c[i] >> d[i];
    GF<int> gf(n*2+2);
    inc(i, 0, n){
        gf.add(n*2, i, 1);
        gf.add(n+i, n*2+1, 1);
        inc(j, 0, n){
            if(a[i] < c[j] && b[i] < d[j]){
                gf.add(i, n+j, 1);
            }
        }
    }
    MF<int> mf(gf);
    cout << mf.query(n*2, n*2+1) << endl;
    return 0;
}
