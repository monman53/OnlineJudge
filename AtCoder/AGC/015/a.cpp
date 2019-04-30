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
    LL n, a, b;cin >> n >> a >> b;
    cout << max(0LL, (a+b*(n-1))-(b+a*(n-1))+1) << endl;
    return 0;
}
