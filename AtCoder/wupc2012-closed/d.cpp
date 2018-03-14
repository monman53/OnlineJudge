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

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int a[100][100];
int dp[100][100];

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    inc(i, 0, n){
        inc(j, 0, i+1){
            cin >> a[i][j];
        }
    }
    inc(i, 0, n){
        dp[n-1][i] = a[n-1][i];
    }
    dec(i, 0, n-1){
        inc(j, 0, i+1){
            dp[i][j] = a[i][j]+max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
