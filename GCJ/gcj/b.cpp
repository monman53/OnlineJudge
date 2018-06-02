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

int dp[55][55][55][55];

int dfs(int r, int b, int rr, int bb) {
    if(dp[r][b][rr][bb] != -1) return dp[r][b][rr][bb];

}

int solve() {
    int R, B;cin >> R >> B;
    mset(dp, -1);
    if(R > 50 || B > 50) return 0;
    return dp[R][B][R+B];
}

int main() {
    //cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
