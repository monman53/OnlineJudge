// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

// 最大公約数
ULL gcd(ULL x, ULL y) {
    return y ? gcd(y, x%y) : x;
}

ULL lcm(ULL m, ULL n) {
    return m/gcd(m, n)*n;
}

int main() {
    int n;cin >> n;
    vector<ULL> t(n);
    for(auto &tt : t) cin >> tt;
    ULL ans = t[0];
    for(int i=1;i<n;i++){
        ans = lcm(ans, t[i]);
    }
    printf("%llu\n", ans);
    return 0;
}
