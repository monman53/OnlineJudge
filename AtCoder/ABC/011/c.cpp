// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    int a, b, c;cin >> a >> b >> c;
    vector<int> dp(305, 105);
    dp[n] = 0;
    dp[a] = 200;
    dp[b] = 200;
    dp[c] = 200;
    for(int i=n;i>0;i--){
        for(int j=1;j<=3;j++){
            if(i-j < 0) continue;
            if(dp[i-j] == 200) continue;
            dp[i-j] = min(dp[i-j], dp[i]+1);
        }
    }
    cout << (dp[0] <= 100 ? "YES" : "NO") << endl;
    return 0;
}
