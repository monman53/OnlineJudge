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
    int t;cin >> t;
    int ans = 0;
    for(int i=0;i<5;i++){
        ans += (40*i+t) + (40*i+40-t+1);
    }
    cout << ans << endl;
    return 0;
}
