// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         LLONG_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int b[2000][2000];

int main() {
    std::ios::sync_with_stdio(false);
    LL n, x;cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        b[i][0] = a[i];
        for(int k=1;k<n;k++){
            b[i][k] = min(a[(i-k+n)%n], b[i][k-1]);
        }
    }
    LL ans = INF;
    for(int k=0;k<n;k++){
        LL sum = 0;
        for(int i=0;i<n;i++){
            sum += b[i][k];
        }
        ans = min(ans, k*x+sum);
    }
    cout << ans << endl;
    return 0;
}
