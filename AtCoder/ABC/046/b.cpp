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
    int ans = k;
    for(int i=1;i<n;i++){
        ans *= k-1;
    }
    cout << ans << endl;
    return 0;
}
