// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
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
#define EQ(a, b) (fabs((a)-(b)) < eps)

typedef long long ll;
typedef unsigned long long ull;
// }}}
// number {{{
#define SIZE      100005
#define MOD   1000000007

// べき乗
// verified AOJ NTL_1_B
ll pow(ll a, ll b) {
    if(b == 0) return 1;
    ll aa = pow(a, b/2);
    return aa*aa%MOD*(b%2 == 1 ? a : 1)%MOD;
}

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

ll comb(int n, int r) {
    if(r > n) return 0;
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

ll gcd(ll x, ll y) {
    return y ? gcd(y, x%y) : x;
}
//}}}

int main() {
    fact_init();
    int n, m;
    cin >> n >> m;

    if(n == m){
        cout << fact[n]*fact[m]%MOD*2%MOD << endl;
    }else if(abs(n-m) == 1){
        cout << fact[n]*fact[m]%MOD << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}
