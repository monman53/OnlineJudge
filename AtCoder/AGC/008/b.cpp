// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    vector<LL> a(n), s(n+1), ps(n+1);
    for(int i=0;i<n;i++) cin >> a[i];
    s[0] = ps[0] = 0;
    for(int i=0;i<n;i++){
        s[i+1] = s[i] + a[i];
        ps[i+1] = ps[i];
        if(a[i] > 0) ps[i+1] = ps[i] + a[i];
    }
    LL ans = 0;
    for(int i=0;i<n-k+1;i++){
        ans = max(ans, (ps[i])+(ps[n]-ps[i+k]));
        ans = max(ans, (ps[i])+(s[i+k]-s[i])+(ps[n]-ps[i+k]));
    }
    cout << ans << endl;
    return 0;
}
