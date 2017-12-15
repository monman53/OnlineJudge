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

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

// 最小公倍数
LL lcm(LL m, LL n) {
    return m/gcd(m, n)*n;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    LL ans = 1;
    for(int i=0;i<n;i++){
        LL a;cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans << endl;
    return 0;
}
