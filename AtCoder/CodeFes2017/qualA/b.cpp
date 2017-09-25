// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k;cin >> n >> m >> k;
    string ans = "No";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*m + j*n - 2*i*j == k) ans = "Yes";
        }
    }
    cout << ans << endl;
    return 0;
}
