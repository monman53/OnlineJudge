// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, t;cin >> n >> t;
    int imos[100005];
    for(int i=0;i<=t;i++){
        imos[i] = 0;
    }
    for(int i=0;i<n;i++){
        int l, r;cin >> l >> r;
        imos[l]++;
        imos[r]--;
    }
    int ans = 0;
    int now = 0;
    for(int i=0;i<=t;i++){
        now += imos[i];
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
