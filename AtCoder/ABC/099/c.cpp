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

int dp[100001];
int v[11] = {6, 6*6, 6*6*6, 6*6*6*6, 6*6*6*6*6, 6*6*6*6*6*6, 
             9, 9*9, 9*9*9, 9*9*9*9, 9*9*9*9*9};

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    dp[0] = 0;
    inc(i, 1, n+1){
        dp[i] = dp[i-1]+1;
        inc(j, 0, 11){
            if(i-v[j] >= 0){
                dp[i] = min(dp[i], dp[i-v[j]]+1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
