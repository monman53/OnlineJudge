// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, k;cin >> n >> k;
    double ans = 0;
    // K K K
    ans += 1;
    // K K x
    // K x K
    // K K x
    ans += (n-1)*3;
    // K x y
    // x K y
    // x y K
    ans += (k-1)*(n-k)*6;

    ans /= n;
    ans /= n;
    ans /= n;

    printf("%.10lf\n", ans);
    return 0;
}
