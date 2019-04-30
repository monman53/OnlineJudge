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
    int l;cin >> l;
    string s;cin >> s;
    int n = s.size();
    cout << s.substr(0, min(l, n)) << endl;
    return 0;
}
