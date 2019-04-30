// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, W;cin >> n >> W;
    int v[100], w[100];
    for(int i=0;i<n;i++){
        cin >> v[i] >> w[i];
    }

    int dp[101][10001];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            dp[i+1][j] = dp[i][j];
        }
        for(int j=0;j<=W;j++){
            int nj = j + w[i];
            if(nj > W) continue;
            dp[i+1][nj] = max({dp[i+1][nj], dp[i][j] + v[i], dp[i+1][j] + v[i]});
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}
