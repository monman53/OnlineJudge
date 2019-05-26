// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

#define SIZE 200010LL

// べき乗
// verified AOJ NTL_1_B
LL mpow(LL a, LL b) {
    if(b == 0LL) return 1LL;
    LL aa = mpow(a, b/2LL);
    return aa*aa%MOD*(b%2LL == 1LL ? a : 1LL)%MOD;
}

// 階乗と階乗の逆元
// ARC077D
LL fact[SIZE] = {1LL, 1LL};
LL finv[SIZE] = {1LL, 1LL};

void initFact() {
    // fact
    for(LL i=2LL;i<SIZE;i++){
        fact[i] = fact[i-1LL]*i%MOD;
    }

    // finv
    finv[SIZE-1] = mpow(fact[SIZE-1LL], MOD-2LL);
    for(LL i=SIZE-1LL;i>=3LL;i--){
        finv[i-1LL] = finv[i]*i%MOD;
    }
}

// 組み合わせの数
// ARC077D
LL comb(LL n, LL r) {
    if(r > n) return 0LL;
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL n, m;cin >> n >> m;
    if(n < 3 || m < 1){
        cout << 0 << endl;
        return 0;
    }
    LL ans = 0;
    inc(i, 0, n+m-3){
        MODA(ans, );
    }
    return 0;
}
