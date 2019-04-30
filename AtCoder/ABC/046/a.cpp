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
    int a, b, c;cin >> a >> b >> c;
    int ans = 3;
    if(a == b) ans--;
    if(b == c) ans--;
    if(c == a) ans--;
    if(a == b && b == c && c == a) ans++;
    cout << ans << endl;
    return 0;
}
