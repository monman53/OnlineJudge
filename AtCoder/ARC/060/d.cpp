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

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}

ll f(ll b, ll n) {
    if(n < b){
        return n;
    }else{
        return f(b, n/b) + n%b;
    }
}

int main() {
    ll n, s;cin >> n >> s;
    if(s == n){
        printf("%lld\n", n+1LL);
        return 0;
    }
    if(s > n){
        printf("%d\n", -1);
        return 0;
    }
    for(ll b=2LL;b*b<=n;b++){
        if(f(b, n) == s){
            printf("%lld\n", b);
            return 0;
        }
    }
    vector<ll> ans;
    for(ll p=1LL;p*p<n;p++){
        ll b = (n-s)/p+1LL;
        if((n-s)%p == 0){
            if(f(b, n) == s){
                ans.push_back(b);
            }
        }
    }
    if(ans.size() == 0){
        printf("%d\n", -1);
    }else{
        printf("%lld\n", *min_element(ans.begin(), ans.end()));
    }
    return 0;
}
