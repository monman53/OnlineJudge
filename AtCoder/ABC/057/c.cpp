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
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

int f(ll a, ll b) {
    int acount = 0, bcount = 0;
    while(a > 0L){
        a/=10L;
        acount++;
    }
    while(b > 0L){
        b/=10L;
        bcount++;
    }
    return max(acount, bcount);
}

int main() {
    ll n;cin >> n;
    int ans = 10000;
    for(ll i=1L;i*i<=n;i++){
        ll j = n/i;
        if(n%i == 0L){
            ans = min(ans, f(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}
