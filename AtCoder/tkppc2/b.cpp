// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    int dp[501][501];
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<n;i++){
        int v, t;cin >> v >> t;
        for(int j=0;j<501;j++){
            if(dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+t > 500) continue;
            dp[i+1][j+t] = max(dp[i+1][j+t], dp[i][j]+v);
        }
    }
    int ans = 0;
    for(int i=0;i<=m;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
