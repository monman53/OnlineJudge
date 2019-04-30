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
    string a, b, c;cin >> a >> b >> c;
    string ans = "YES";
    if(a[a.size()-1] != b[0]) ans = "NO";
    if(b[b.size()-1] != c[0]) ans = "NO";
    cout << ans << endl;
    return 0;
}
