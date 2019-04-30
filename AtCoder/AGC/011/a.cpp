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
    int n, c, k;cin >> n >> c >> k;
    vector<int> t(n);
    for(int i=0;i<n;i++) cin >> t[i];
    sort(t.begin(), t.end());
    int ans = 1;
    int b = 0;
    for(int i=1;i<n;i++){
        if(t[b]+k < t[i] || i-b+1 > c){
            ans++;
            b = i;
        }
    }
    cout << ans << endl;
    return 0;
}
