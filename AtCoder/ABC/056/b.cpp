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
    int w, a, b;cin >> w >> a >> b;
    if(a > b) swap(a, b);
    cout << max(0, b-(a+w)) << endl;
    return 0;
}
