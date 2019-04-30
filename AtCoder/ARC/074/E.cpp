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

#define kita            cout << "kita\n"
#define print2(i, n)    cout << (i) << ": " << (n) << endl
#define print3(i, j, n)     cout << "(" << (i) << ", " << (j) << ") : " << (n) << endl
#define print4(i, j, n, m)  cout << "(" << (i) << ", " << (j) << ") : " << (n) << ", " << (m) << endl
#define print_mat(mat, h, w) for(int i=0;i<(h);i++){for(int j=0;j<(w);j++){cout << mat[i][j] << " ";}cout << endl;}

#define EPS (1e-10)
#define EQ(a, b) (abs((a)-(b)) < EPS)

typedef long long ll;
typedef unsigned long long ull;
// }}}
// number {{{
#define SIZE 100005
#define MOD  1000000007LL

// べき乗
// verified AOJ NTL_1_B
ll pow(ll a, ll b) {
    if(b == 0) return 1;
    ll aa = pow(a, b/2);
    return aa*aa%MOD*(b%2 == 1 ? a : 1)%MOD;
}

// 階乗と階乗の逆元
// ARC077D
ll fact[SIZE] = {1, 1};
ll finv[SIZE] = {1, 1};

void fact_init() {
    // fact
    for(ll i=2;i<SIZE;i++){
        fact[i] = fact[i-1]*i%MOD;
    }

    // finv
    finv[SIZE-1] = pow(fact[SIZE-1], MOD-2);
    for(ll i=SIZE-1;i>=3;i--){
        finv[i-1] = finv[i]*i%MOD;
    }
}

// 組み合わせの数
// ARC077D
ll comb(int n, int r) {
    if(r > n) return 0;
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

// 最小公約数
ll gcd(ll x, ll y) {
    return y ? gcd(y, x%y) : x;
}
//}}}

int main() {
    fact_init();
    int n, m;cin >> n >> m;
    ll ans = 1;
    for(int i=0;i<m;i++){
        ll l, r, x;cin >> l >> r >> x;
        ll p1 = pow(1LL, r-l+1LL)*comb(3, 1) % MOD;
        ll p2 = (pow(2LL, r-l+1LL)*comb(3, 2) % MOD - p1 + MOD) % MOD;
        ll p3 = (pow(3LL, r-l+1LL)*comb(3, 3) % MOD - p2 + MOD) % MOD;
        if(x == 1){
            ans = ans*p1 % MOD;
        }else if(x == 2){
            ans = ans*p2 % MOD;
        }else{
            ans = ans*p3 % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
