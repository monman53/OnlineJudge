// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int a[1000][1000];
int dp[1000][1000];
int h, w;

int solve(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    int res = 1;
    inc(k, 0, 4){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni >= 0 && ni < h && nj >= 0 && nj < w){
            if(a[ni][nj] < a[i][j]){
                res += solve(ni, nj);
                res %= MOD;
            }
        }
    }
    return dp[i][j] = res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> h >> w;
    inc(i, 0, h){
        inc(j, 0, w){
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    inc(i, 0, h){
        inc(j, 0, w){
            ans += solve(i, j);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
