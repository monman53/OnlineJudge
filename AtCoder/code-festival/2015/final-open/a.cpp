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
    string s, t, u;cin >> s >> t >> u;
    string ans = "valid";
    if((int)s.size() != 5) ans = "invalid";
    if((int)t.size() != 7) ans = "invalid";
    if((int)u.size() != 5) ans = "invalid";
    cout << ans << endl;
    return 0;
}
