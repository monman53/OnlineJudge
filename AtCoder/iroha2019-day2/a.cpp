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

int dp[5001][5001];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    inc(i, 0, n){
        inc(j, 0, n){
            if(s[i] == t[j]){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        }
    }
    int ans = 0;
    inc(i, 0, n+1){
        inc(j, 0, n+1){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans+1 << endl;
    return 0;
}
