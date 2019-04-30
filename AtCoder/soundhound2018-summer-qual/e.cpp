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

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

struct E {
    int to;
    LL w;
};
using G = vector<vector<E>>;

G g;

LL ans_min = 1;
LL ans_max = LLONG_MAX;
bool flag = true;

LL visited[100000][2];

void dfs(int from, int to, LL s, int p) {
    if(p == 0){
        ans_min = max(ans_min, 1-s);
    }
    if(p == 1){
        ans_max = min(ans_max, s-1);
    }
    if(ans_max < ans_min) flag = false;
    if(visited[to][p] != LLONG_MIN){
        return;
    }
    visited[to][p] = s;
    for(auto next : g[to]){
        if(next.to == from) continue;
        dfs(to, next.to, next.w-s, 1-p);
    }
    return;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    g.resize(n);
    inc(i, 0, n){
        visited[i][0] = visited[i][1] = LLONG_MIN;
    }
    inc(i, 0, m){
        int u, v;
        LL s;
        cin >> u >> v >> s;
        u--;v--;
        g[u].pb({v, s});
        g[v].pb({u, s});
    }
    dfs(-1, 0, 0, 0);
    //cout << flag << " " << ans_min << " " << ans_max << endl;
    if(ans_max >= ans_min && flag){
        cout << ans_max-ans_min+1LL << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
