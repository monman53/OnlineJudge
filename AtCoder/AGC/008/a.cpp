// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int sgn(int n) {
    if(n < 0) return -1;
    if(n > 0) return 1;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    int x, y;cin >> x >> y;
    int ans = 0;
    ans += abs(abs(x)-abs(y));
    if(x > y){
        int s = sgn(x)*sgn(y);
        if(s == 1){
            ans += 2;
        }else{
            ans += 1;
        }
    }else{
        int s = sgn(x)*sgn(y);
        if(s == -1){
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
