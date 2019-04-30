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
    int n, m;cin >> n >> m;
    int dp[25][50005];
    // dp[i][j] : iまでのコインを使ってj円をつくる時の枚数のmin
    int c[20];
    for(int i=0;i<m;i++){
        cin >> c[i];
    }
    sort(c, c+m);

    for(int i=0;i<=n;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j=0;j<=n;j++){
            int nj = j+c[i];
            if(nj <= n){
                dp[i][nj] = min(dp[i][nj], dp[i][j]+1);
            }
        }
    }

    cout << dp[m-1][n] << endl;
    return 0;
}
