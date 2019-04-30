// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int sum(int n) {
    int ret = 0;
    while(n > 0){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b;cin >> n >> a >> b;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int s = sum(i);
        if(a <= s && s <= b){
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
