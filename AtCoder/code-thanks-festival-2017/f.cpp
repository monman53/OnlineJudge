// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int n, k;
vector<int> a;
vector<vector<int>> memo;

LL solve(int i, int now) {
    if(i == n){
        if(now == k){
            return 1LL;
        }else{
            return 0LL;
        }
    }
    if(memo[i][now] != -1){
        return memo[i][now];
    }
    return memo[i][now] = (solve(i+1, now^a[i]) + solve(i+1, now))%MOD;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    memo.resize(n, vector<int>(100000-(n-1)+1, -1));
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << solve(0, 0) << endl;
    return 0;
}
