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
    int h, w, q;cin >> h >> w >> q;
    imos[2505][2505];
    memset(imos, 0, sizeof(imos));
    for(int i=0;i<q;i++){
        int t, i1, j1, i2, j2;
        cin >> t >> t1 >> j1 >> i2 >> j2;
        if(t == 1){
            imos[i1][j1]++;
            imos[i1][j2+1]--;
            imos[i2+1][j1]--;
            imos[i2+1][j2+1]++;
        }
    }
    return 0;
}
