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
    double r1, r2;cin >> r1 >> r2;
    printf("%.8f", 1/(1/r1+1/r2));
    return 0;
}
