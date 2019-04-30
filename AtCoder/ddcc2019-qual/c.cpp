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

LL mpow(LL a, LL b) {
    if(b == 0) return 1;
    LL aa = mpow(a, b/2);
    return aa*aa%MOD*(b%2 == 1 ? a : 1)%MOD;
}

// 階乗と階乗の逆元
// ARC077D
#define SIZE 200010
LL fact[SIZE] = {1, 1};
LL finv[SIZE] = {1, 1};

void initFact() {
    // fact
    for(LL i=2;i<SIZE;i++){
        fact[i] = fact[i-1]*i%MOD;
    }

    // finv
    finv[SIZE-1] = mpow(fact[SIZE-1], MOD-2);
    for(LL i=SIZE-1;i>=3;i--){
        finv[i-1] = finv[i]*i%MOD;
    }
}

// 組み合わせの数
// ARC077D
LL comb(int n, int r) {
    if(r > n) return 0;
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    initFact();
    LL n;cin >> n;
    LL ans = 0;
    for(LL mx=1;mx<=100000;mx++){
        if(n/mx < 1) continue;
        LL a = mpow(n/mx, 10);

        if(mx != 1){
            LL b = 0;
            for(LL i=1;i<=10;i++){
                LL c = comb(10, i);
                MODP(c, mpow(mx-1, 10-i));
                MODA(b, c);
            }
            MODP(a, b);
        }
        MODA(ans, a);
    }
    printf("%lld\n", ans);
    return 0;
}
