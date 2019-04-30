// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

G g;
vector<bool> visited;

bool dfs(int from, int to){
    bool res = true;
    if(visited[to]) return false;
    visited[to] = 1;
    for(auto next : g[to]){
        if(next == from) continue;
        res &= dfs(to, next);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    g.resize(n);
    visited.resize(n, false);
    inc(i, 0, m){
        int u, v;cin >> u >> v;u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    inc(i, 0, n){
        if(visited[i]) continue;
        if(dfs(-1, i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
