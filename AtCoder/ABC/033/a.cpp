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
    string s;cin >> s;
    string ans = "SAME";
    if(s[0] != s[1]) ans = "DIFFERENT";
    if(s[1] != s[2]) ans = "DIFFERENT";
    if(s[2] != s[3]) ans = "DIFFERENT";
    cout << ans << endl;
    return 0;
}
