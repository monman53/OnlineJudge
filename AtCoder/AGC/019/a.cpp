// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL q, h, s, d;cin >> q >> h >> s >> d;
    LL n;cin >> n;
    LL ans = 0LL;
    if(q*8LL > d && h*4LL > d && s*2LL > d){
        ans += n/2LL*d;
        n %= 2LL;
    }
    ans += n*min({q*4LL, h*2LL, s});
    cout << ans << endl;
    return 0;
}
