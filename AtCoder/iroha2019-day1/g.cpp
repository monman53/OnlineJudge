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

LL dp[400][400];
LL a[400];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n, m, k;cin >> n >> m >> k;
    inc(i, 1, n+1){
        cin >> a[i];
    }
    dp[0][0] = 1;
    inc(i, 0, n){
        inc(j, 0, m){
            if(dp[i][j] > 0){
                inc(l, 1, k+1){
                    if(i+l <= n && j+1 <= m){
                        dp[i+l][j+1] = max(dp[i+l][j+1], dp[i][j]+a[i+l]);
                    }
                }
            }
        }
    }
    LL ans = 0;
    inc(i, n+1-k, n+1){
        ans = max(ans, dp[i][m]);
        //cout << dp[i][m] << endl;
    }
    cout << ans-1 << endl;
    return 0;
}
