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
    ll n, x;cin >> n >> x;
    vector<ll> a(n);
    ll ans = 0;
    for(auto &aa : a){
        cin >> aa;
        if(aa > x){
            ans += aa - x;
            aa = x;
        }
    }
    for(int i=0;i<n-1;i++){
        if(a[i] + a[i+1] > x){
            ans += a[i] + a[i+1] - x;
            a[i+1] -= a[i] + a[i+1] - x;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
