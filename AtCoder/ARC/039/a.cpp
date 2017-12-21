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
    int a, b;cin >> a >> b;
    int ans = a-b;
    for(int i=100;i>=1;i/=10){
        int aa = a/i%10;
        int bb = b/i%10;
        if(i == 100){
            if(aa == 9 && bb == 1) continue;
            ans += i*max(bb-1, 9-aa);
            break;
        }else{
            if(aa == 9 && bb == 0) continue;
            ans += i*max(bb-0, 9-aa);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
