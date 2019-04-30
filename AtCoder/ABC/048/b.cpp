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
    LL a, b, x;cin >> a >> b >> x;
    cout << b/x - max(a-1, 0LL)/x + (a == 0) << endl;
    return 0;
}
