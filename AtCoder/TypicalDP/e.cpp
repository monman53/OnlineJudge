// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

LL dp[10005][2][100];

int main() {
    std::ios::sync_with_stdio(false);
    int D;cin >> D;
    string s;cin >> s;
    int n = s.size();
    dp[0][0][0] = 1;
    inc(i, 0, n){
        int d = s[i]-'0';
        inc(j, 0, 2){
            int dmax = j ? 9 : d;
            inc(k, 0, D){
                inc(l, 0, dmax+1){
                    MODA(dp[i+1][j || l < dmax][(k+l)%D], dp[i][j][k]);
                }
            }
        }
    }
    LL ans = -1;
    inc(i, 0, 2){
        MODA(ans, dp[n][i][0]);
    }
    cout << ans << endl;
    return 0;
}
