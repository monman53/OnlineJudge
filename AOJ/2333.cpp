// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int main() {
    LL n, W;cin >> n >> W;
    vector<LL> w(n);
    LL sum = 0;
    for(int i=0;i<n;i++){
        cin >> w[i];
        sum += w[i];
    }
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    vector<vector<LL>> dp(sum+1, vector<LL>(n+1, 0));
    dp[0][0] = 1;
    for(int i=0;i<W;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] > 0){
                dp[i+w[j]][j+1] = (dp[i+w[j]][j+1]+dp[i][j])%MOD;
                dp[i][j+1] = (dp[i][j+1]+dp[i][j])%MOD;
            }
        }
    }

    for(int i=0;i<=W;i++){
        for(int j=0;j<=n;j++){
            cout << dp[i][j];
        }
        cout << endl;
    }

    LL ans = 0;
    int mmax = -1;
    for(int i=W;i>=0;i--){
        for(int j=mmax+1;j<=n;j++){
            if(dp[i][j] > 0){
                cout << i << " " << j << endl;
                ans = (ans+dp[i][j])%MOD;
                mmax = j;
                break;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
