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
    int n, k;cin >> n >> k;
    vector<int> l(n);
    for(int i=0;i<n;i++) cin >> l[i];
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());

    int ans = 0;
    for(int i=0;i<k;i++){
        ans += l[i];
    }
    cout << ans << endl;
    return 0;
}
