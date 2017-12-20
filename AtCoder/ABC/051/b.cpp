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
    int k, s;cin >> k >> s;
    LL ans = 0;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
            if(0 <= s-x-y && s-x-y <= k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
