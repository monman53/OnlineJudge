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
    double ans = 0.0;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        double a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        ans = max(ans, a+b+c+d+e*110/900);
    }
    printf("%.5f\n", ans);
    return 0;
}
