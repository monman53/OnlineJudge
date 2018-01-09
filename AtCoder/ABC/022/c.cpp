// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    int a[300][300];
    int b[300][300];
    inc(i, 0, n)
        inc(j, 0, n)
            a[i][j] = b[i][j] = INF;

    inc(i, 0, m){
        int u, v, l;cin >> u >> v >> l;
        u--;v--;
        a[u][v] = a[v][u] = l;
        if(u == 0 || v == 0) continue;
        b[u][v] = b[v][u] = l;
    }

    inc(k, 0, n)
        inc(i, 0, n)
            inc(j, 0, n)
                b[i][j] = min(b[i][j], b[i][k]+b[k][j]);

    int ans = INF;
    inc(i, 0, n){
        inc(j, 0, n){
            if(i == 0) continue;
            if(j == 0) continue;
            if(i == j) continue;
            if(a[0][i] == INF) continue;
            if(a[j][0] == INF) continue;
            if(b[i][j] == INF) continue;
            ans = min(ans, a[0][i]+b[i][j]+a[j][0]);
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}
