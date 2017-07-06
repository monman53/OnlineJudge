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
    ll n, m;cin >> n >> m;
    ll ans = 0;
    if(m%2 == 1){
        m--;
    }
    if(2*n >= m){
        ans += m/2;
    }else{
        ans += n;
        m -= 2*n;
        if(m > 0){
            ans += m/4;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
