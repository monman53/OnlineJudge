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

int main() {
    ll n, k;cin >> n >> k;
    vector<ll> s(n);
    for(auto &ss : s) cin >> ss;
    for(auto ss: s) if(ss == 0) {cout << n << endl;return 0;}
    int l=0, r=0;
    int ans = 0;
    ll now = s[0];
    while(true){
        if(now <= k){
            ans = max(ans, r-l+1);
            r++;
            if(r == n) break;
            now *= s[r];
        }else{
            if(l == r){
                now /= s[l];
                l++;
                r++;
                if(r == n) break;
                now *= s[r];
            }else{
                now /= s[l];
                l++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
