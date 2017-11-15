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

LL sum(LL n){
    LL ret = 0LL;
    while(n > 0LL){
        ret += n%10LL;
        n /= 10LL;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    LL k;cin >> k;
    LL ans = sum(k);
    for(LL i=1LL;i<=100005;i++){
        ans = min(ans, sum(i*k));
    }
    cout << ans << endl;
    return 0;
}
