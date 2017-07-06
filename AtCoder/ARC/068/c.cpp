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

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    ll x;cin >> x;
    ll ans = 0;
    ans = x/11*2;
    if(x%11 != 0){
        ans++;
        if(x%11 > 6){
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
