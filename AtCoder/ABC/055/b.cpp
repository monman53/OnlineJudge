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
    LL n;cin >> n;
    LL ans = 1;
    for(LL i=1LL;i<=n;i++){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
