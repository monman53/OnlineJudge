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
    vector<LL> sum(n, 0);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    sum[0] = a[0];
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    int ans = 1;
    for(int i=n-2;i>=0;i--){
        //cout << sum[i] << endl;
        if(2*sum[i] >= a[i+1]) ans++;
        else break;
    }
    cout << ans << endl;
    return 0;
}
