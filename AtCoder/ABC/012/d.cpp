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
    int d[300][300];
    inc(i, 0, n)
        inc(j, 0, n)
            d[i][j] = (i==j ? 0 : INF);
    inc(i, 0, m){
        int a, b, t;cin >> a >> b >> t;
        a--;b--;
        d[a][b] = d[b][a] = t;
    }
    inc(k, 0, n)
        inc(i, 0, n)
            inc(j, 0, n)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    int ans = INF;
    inc(i, 0, n){
        int mmax = 0;
        inc(j, 0, n){
            if(d[i][j] == INF) continue;
            mmax = max(mmax, d[i][j]);
        }
        ans = min(ans, mmax);
    }
    cout << ans << endl;
    return 0;
}
