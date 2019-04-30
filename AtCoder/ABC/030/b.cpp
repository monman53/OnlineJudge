// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    n %= 12;
    double dn = 360*n/12.0+30*m/60.0;
    double dm = 360*m/60.0;
    double dd = abs(dm-dn);
    printf("%.5f\n", min(dd, 360-dd));
    return 0;
}
