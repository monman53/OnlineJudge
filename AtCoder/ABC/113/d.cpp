// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

LL dp[101][8];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int h, w, k;
    cin >> h >> w >> k;
    dp[0][0] = 1;
    inc(i, 0, h){
        inc(bit, 0, 1 << (w-1)){
            bool flag = false;
            inc(j, 0, w-1){
                if(bit >> j & 1 && bit >> j+1 & 1){
                    flag = true;
                }
            }
            if(flag) continue;

            inc(j, 0, w){
                if(bit >> j-1 & 1){
                    MODA(dp[i+1][j], dp[i][j-1]);
                }else if(bit >> j & 1){
                    MODA(dp[i+1][j], dp[i][j+1]);
                }else{
                    MODA(dp[i+1][j], dp[i][j]);
                }
            }
        }
    }
    cout << dp[h][k-1] << endl;
    return 0;
}
