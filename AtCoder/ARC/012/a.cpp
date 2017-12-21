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
    map<string, int> m;
    m["Sunday"] = 0;
    m["Monday"] = 5;
    m["Tuesday"] = 4;
    m["Wednesday"] = 3;
    m["Thursday"] = 2;
    m["Friday"] = 1;
    m["Saturday"] = 0;
    string s;cin >> s;
    cout << m[s] << endl;
    return 0;
}
