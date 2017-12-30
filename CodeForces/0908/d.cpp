// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// べき乗
// verified AOJ NTL_1_B
LL mpow(LL a, LL b) {
    if(b == 0) return 1;
    LL aa = mpow(a, b/2);
    return aa*aa%MOD*(b%2 == 1 ? a : 1)%MOD;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout << 341*mpow(100LL, MOD-2LL)%MOD << endl;
    return 0;
}
