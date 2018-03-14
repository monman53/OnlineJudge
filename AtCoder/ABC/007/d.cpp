// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  (a)=((a)+(b))%MOD
#define MODP(a, b)  (a)=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

LL dp[25][2][2];

LL solve(LL n) {
    string s = to_string(n);
    int m = s.size();
    mset(dp, 0);
    dp[0][0][0] = 1;
    inc(i, 0, m){
        int d = s[i]-'0';
        inc(j, 0, 2){
            int maxd = j ? 9 : d;
            inc(k, 0, 2){
                inc(l, 0, maxd+1){
                    dp[i+1][j || l < maxd][k || l == 4 || l == 9] += dp[i][j][k];
                }
            }
        }
    }
    LL ans = 0;
    inc(i, 0, 2){
        ans += dp[m][i][1];
    }
    return ans;
}


int main() {
    std::ios::sync_with_stdio(false);
    LL a, b;cin >> a >> b;
    cout << solve(b) - solve(a-1) << endl;
    return 0;
}
