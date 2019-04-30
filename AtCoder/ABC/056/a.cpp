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
    char a, b;cin >> a >> b;
    map<pair<char, char>, char> m;
    m[{'H', 'H'}] = 'H';
    m[{'H', 'D'}] = 'D';
    m[{'D', 'H'}] = 'D';
    m[{'D', 'D'}] = 'H';
    cout << m[{a, b}] << endl;
    return 0;
}
