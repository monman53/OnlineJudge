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

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    int a[20];
    for(int i=0;i<n;i++) cin >> a[i];
    bool dp[40005];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(int i=0;i<n;i++){
        for(int j=40000;j>=0;j--){
            if(dp[j]) dp[j+a[i]] = true;
        }
    }
    int q;cin >> q;
    for(int i=0;i<q;i++){
        int m;cin >> m;
        cout << (dp[m] ? "yes" : "no") << endl;
    }
    return 0;
}
