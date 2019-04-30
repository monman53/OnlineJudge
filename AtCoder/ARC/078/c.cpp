// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
// #include <tuple>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

// template<class T>
// using P = pair<T, T>;
using ll  = long long;
using ull = unsigned long long;
// }}}

int main() {
    int n;cin >> n;
    vector<ll> s(n+1);
    s[0] = 0LL;
    for(int i=1;i<=n;i++){
        ll a;cin >> a;
        s[i] = s[i-1]+a;
    }

    ll ans = 1000000000LL*1000000LL;
    for(int i=1;i<n;i++){
        ans = min(ans, abs(s[n]-s[i]-s[i]));
    }
    printf("%lld\n", ans);
    return 0;
}
