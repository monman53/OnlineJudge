// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

double R[1024];
double dp[11][1024];

void dfs(int k, int l, int r){
    if(k == 0) return;
    int c = (l+r)/2;
    dfs(k-1, l, c);
    dfs(k-1, c, r);
    for(int i=l;i<c;i++){
        for(int j=c;j<r;j++){
            dp[k][i] += dp[k-1][i]*dp[k-1][j]/(1+pow(10, (R[j]-R[i])/400));
            dp[k][j] += dp[k-1][j]*dp[k-1][i]/(1+pow(10, (R[i]-R[j])/400));
        }
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));
    int k;cin >> k;
    for(int i=0;i<(1<<k);i++){
        cin >> R[i];
        dp[0][i] = 1.0;
    }
    dfs(k, 0, 1<<k);
    for(int i=0;i<(1<<k);i++){
        printf("%.9lf\n", dp[k][i]);
    }
    return 0;
}
