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
    int h, w;cin >> h >> w;
    int c[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> c[i][j];
        }
    }
    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a;cin >> a;
            if(a == 1 || a == -1) continue;
            ans += c[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}
