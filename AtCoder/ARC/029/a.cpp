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
    int n;cin >> n;
    vector<int> t(4, 0);
    for(int i=0;i<n;i++) cin >> t[i];
    int ans = 100000;
    ans = min(ans, max(t[0]+t[1], t[2]+t[3]));
    ans = min(ans, max(t[0]+t[2], t[1]+t[3]));
    ans = min(ans, max(t[0]+t[3], t[1]+t[2]));
    ans = min(ans, max(t[0], t[1]+t[2]+t[3]));
    ans = min(ans, max(t[1], t[0]+t[2]+t[3]));
    ans = min(ans, max(t[2], t[0]+t[1]+t[3]));
    ans = min(ans, max(t[3], t[0]+t[1]+t[2]));
    cout << ans << endl;
    return 0;
}
