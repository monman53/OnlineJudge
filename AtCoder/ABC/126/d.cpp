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

vector<vector<pair<int, int>>> g;
int ans[100000];

void dfs(int now, int to, int from) {
    ans[to] = now;
    for(auto next : g[to]){
        if(next.fi == from) continue;
        if(next.se%2 == 1){
            dfs(1-now, next.fi, to);
        }else{
            dfs(now, next.fi, to);
        }
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    g.resize(n);
    inc(i, 0, n-1){
        int a, b;cin >> a >> b;
        a--;b--;
        int w;cin >> w;
        g[a].pb({b, w});
        g[b].pb({a, w});
    }
    dfs(0, 0, -1);
    inc(i, 0, n){
        cout << ans[i] << endl;
    }
    return 0;
}
