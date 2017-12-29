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
    map<char, string> m;
    m['B'] = "Bachelor";
    m['M'] = "Master";
    m['D'] = "Doctor";
    cout << m[s[2]] << " " << s.substr(0, 2) << endl;
    return 0;
}
