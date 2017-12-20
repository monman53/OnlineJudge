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
    int n, k;cin >> n >> k;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        ans += min(abs(x-k), abs(x))*2;
    }
    cout << ans << endl;
    return 0;
}
