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
    string s, t;cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    cout << (s < t ? "Yes" : "No") << endl;
    return 0;
}
