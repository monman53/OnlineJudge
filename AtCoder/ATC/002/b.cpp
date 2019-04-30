// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3

using LL  = long long;
// }}}

LL MOD;

// べき乗
// verified AOJ NTL_1_B
LL mpow(LL a, LL b) {
    if(b == 0) return 1;
    LL aa = mpow(a, b/2);
    return aa*aa%MOD*(b%2 == 1 ? a : 1)%MOD;
}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, p;cin >> n >> MOD >> p;
    cout << mpow(n, p) << endl;
    return 0;
}
