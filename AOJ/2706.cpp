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
#include <cmath>
using namespace std;

#define alphabet    (26)
#define eps         (1e-10)
#define inf         (1000000005ll)
#define mod         (1000000007ll)
#define eq(a, b)    (abs((a)-(b)) < eps)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}
// number {{{
#define size 200010

// べき乗
// verified aoj ntl_1_b
ll pow(ll a, ll b) {
    if(b == 0) return 1;
    ll aa = pow(a, b/2);
    return aa*aa%mod*(b%2 == 1 ? a : 1)%mod;
}

// 階乗と階乗の逆元
// arc077d
ll fact[size] = {1, 1};
ll finv[size] = {1, 1};

void initfact() {
    // fact
    for(ll i=2;i<size;i++){
        fact[i] = fact[i-1]*i%mod;
    }

    // finv
    finv[size-1] = pow(fact[size-1], mod-2);
    for(ll i=size-1;i>=3;i--){
        finv[i-1] = finv[i]*i%mod;
    }
}

// 組み合わせの数
// arc077d
ll comb(int n, int r) {
    if(r > n) return 0;
    return fact[n]*(finv[r]*finv[n-r]%mod)%mod;
}

// 最小公約数
ll gcd(ll x, ll y) {
    return y ? gcd(y, x%y) : x;
}

// 素数判定 (エラトステネスのふるい)
bool isprime[size];
void initisprime() {
    for(int i=0;i<size;i++){
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    for(int i=2;i*i<=size;i++){
        if(isprime[i]){
            for(int j=i*i;j*j<=size;j+=i){
                isprime[j] = false;
            }
        }
    }
}

// 素因数分解
// verified aoj ntl_1_a
vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> ret;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            int count = 0;
            while(n%i == 0){
                count++;
                n /= i;
            }
            if(count > 0){
                ret.push_back({i, count});
            }
        }
    }
    if(n != 1){
        ret.push_back({n, 1});
    }
    return ret;
}
//}}}

int main() {
    initisprime();
    ll p, q;cin >> p >> q;
    ll n = q/gcd(q, p);
    auto v = factor(n);
    for(auto vv : v){
        if(vv.second > 1){
            for(int i=1;i<vv.second;i++){
                n /= vv.first;
            }
        }
    }
    cout << n << endl;
    return 0;
}
