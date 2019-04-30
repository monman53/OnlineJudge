// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    LL ans = 0;
    for(int i=0;i<n;i++){
        ans += a[i]/2;
        a[i] %= 2;
        if(i == n-1) continue;
        if(a[i] == 1 && a[i+1] > 0){
            ans++;
            a[i] = 0;
            a[i+1]--;
        }
    }
    cout << ans << endl;
    return 0;
}
