// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    ll n, a, b;cin >> n >> a >> b;
    vector<ll> x(n);
    for(auto &xx : x) cin >> xx;
    ll ans = 0;
    for(int i=0;i<n-1;i++){
        ans += min({b, a*(x[i+1]-x[i])});
    }
    printf("%lld\n", ans);
    return 0;
}