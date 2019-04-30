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
    int n;cin >> n;
    int f[100][10];
    int p[100][11];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<2;k++){
                cin >> f[i][j*2+k];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=10;j++){
            cin >> p[i][j];
        }
    }

    int ans = -1000000005;
    for(int i=1;i<1<<10;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int k=0;k<10;k++){
                if(i&(1<<k)){
                    cnt += f[j][k];
                }
            }
            sum += p[j][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
