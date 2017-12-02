// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL k, p;cin >> k >> p;
    LL ans = 0;
    for(LL i=1;i<=k;i++){
        LL a = i;
        LL b = 0LL;
        for(LL j=1LL;j<=i;j*=10LL){
            a *= 10LL;
            b *= 10LL;
            b += i/j%10LL;
        }
        ans = (ans+a+b)%p;
    }
    cout << ans << endl;
    return 0;
}
