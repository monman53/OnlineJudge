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
    int x, a, b;cin >> x >> a >> b;
    char ans = 'A';
    if(abs(x-b) < abs(x-a)) ans = 'B';
    cout << ans << endl;
    return 0;
}
