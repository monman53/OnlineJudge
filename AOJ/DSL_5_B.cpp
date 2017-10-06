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
    int n;cin >> n;
    int imos[1005][1005];
    memset(imos, 0, sizeof(imos));
    for(int i=0;i<n;i++){
        int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
        imos[y1][x1]++;
        imos[y1][x2]--;
        imos[y2][x1]--;
        imos[y2][x2]++;
    }
    int ans = 0;
    for(int i=0;i<=1000;i++){
        int now = 0;
        for(int j=0;j<=1000;j++){
            now += imos[i][j];
            imos[i][j] = now;
        }
    }
    for(int j=0;j<=1000;j++){
        int now = 0;
        for(int i=0;i<=1000;i++){
            now += imos[i][j];
            imos[i][j] = now;
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
