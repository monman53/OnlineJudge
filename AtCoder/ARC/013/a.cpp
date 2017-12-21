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
    int n, m, l;cin >> n >> m >> l;
    int p, q, r;cin >> p >> q >> r;
    int ans = 0;
    ans = max(ans, (n/p)*(m/q)*(l/r));
    ans = max(ans, (n/p)*(m/r)*(l/q));
    ans = max(ans, (n/q)*(m/p)*(l/r));
    ans = max(ans, (n/q)*(m/r)*(l/p));
    ans = max(ans, (n/r)*(m/p)*(l/q));
    ans = max(ans, (n/r)*(m/q)*(l/p));
    cout << ans << endl;
    return 0;
}
