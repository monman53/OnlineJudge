// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

int dp[41][401][401];

int main() {
    std::ios::sync_with_stdio(false);
    int n, ma, mb;cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<401;j++){
            for(int k=0;k<401;k++){
                dp[i][j][k] = INF;
            }
        }
        dp[i][0][0] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<401;j++){
            for(int k=0;k<401;k++){
                if(dp[i][j][k] != INF){
                    dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
                    dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                }
            }
        }
    }
    int ans = INF;
    for(int i=1;i<401;i++){
        for(int j=1;j<401;j++){
            int g = gcd(i, j);
            if(i/g == ma && j/g == mb){
                //cout << dp[n][i][j] << endl;
                ans = min(ans, dp[n][i][j]);
            }
        }
    }
    cout << (ans==INF?-1:ans) << endl;
    return 0;
}
