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
    int n, s, t;cin >> n >> s >> t;
    int w;cin >> w;
    int ans = s <= w && w <= t ? 1 : 0;
    for(int i=0;i<n-1;i++){
        int a;cin >> a;
        w += a;
        ans += s <= w && w <= t ? 1 : 0;
    }
    cout << ans << endl;
    return 0;
}
