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
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int h, w, d;cin >> h >> w >> d;
    char ans[500][500];
    char c[4] = {'R', 'Y', 'G', 'B'};
    if(d%2 == 0){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){

            }
        }
    }else{
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                ans[i][j] = c[(i+j)%2];
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
