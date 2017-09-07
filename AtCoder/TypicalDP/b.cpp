// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int dp[1001][1001];
int A, B;
int a[1000], b[1000];

int dfs(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == A && j == B) return 0;
    bool t = ((i+j)%2 == 0);
    if(i == A){
        return dp[i][j] = dfs(i, j+1) + (t ? b[j] : 0);
    }else if(j == B){
        return dp[i][j] = dfs(i+1, j) + (t ? a[i] : 0);
    }else{
        int aa = dfs(i+1, j);
        int bb = dfs(i, j+1);
        int mmax = max(aa+a[i], bb+b[j]);
        int mmin = min(aa, bb);
        return dp[i][j] = (t ? mmax : mmin);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> A >> B;
    for(int i=0;i<A;i++) cin >> a[i];
    for(int i=0;i<B;i++) cin >> b[i];
    cout << dfs(0, 0) << endl;
    return 0;
}
