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
    vector<int> a(3*n);
    for(int i=0;i<3*n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    LL ans = 0;
    for(int i=0;i<n;i++){
        ans += a[i*2+1];
    }
    cout << ans << endl;
    return 0;
}
