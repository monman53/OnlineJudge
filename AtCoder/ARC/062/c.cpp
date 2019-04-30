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
    ll n;cin >> n;
    ll t, a;cin >> t >> a;
    for(ll i=1;i<n;i++){
        ll tt, aa;cin >> tt >> aa;
        for(ll j=max(t/tt, a/aa);;j++){
            if(tt*j >= t && aa*j >= a){
                t = tt*j;
                a = aa*j;
                break;
            }
        }
    }
    printf("%lld\n", t+a);
    return 0;
}
