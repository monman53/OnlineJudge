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
    int ans = 0;
    for(int i=1;i<=100;i++){
        if(i%3 == 0) continue;
        if(i%5 == 0) continue;
        ans += i;
    }
    cout << ans << endl;
    return 0;
}
