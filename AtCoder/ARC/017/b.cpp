// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 1;
    int ans = 0;
    for(int i=1;i<n;i++){
        if(a[i-1] < a[i]){
            cnt++;
        }else{
            ans += max(0, cnt-k+1);
            cnt=1;
        }
    }
    ans += max(0, cnt-k+1);
    cout << ans << endl;
    return 0;
}
