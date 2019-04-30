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
    int n, a, b;cin >> n >> a >> b;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i < 5){
            ans += b;
        }else{
            ans += a;
        }
    }
    cout << ans << endl;
    return 0;
}
