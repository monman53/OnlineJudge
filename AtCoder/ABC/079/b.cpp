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
    LL ans[100];
    ans[0] = 2;
    ans[1] = 1;
    int n;cin >> n;
    for(int i=2;i<=n;i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    cout << ans[n] << endl;
    return 0;
}
