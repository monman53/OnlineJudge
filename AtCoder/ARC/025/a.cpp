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
    vector<int> d(7), j(7);
    for(int i=0;i<7;i++) cin >> d[i];
    for(int i=0;i<7;i++) cin >> j[i];
    int ans = 0;
    for(int i=0;i<7;i++){
        ans += max(d[i], j[i]);
    }
    cout << ans << endl;
    return 0;
}
