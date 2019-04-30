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
    int n;cin >> n;
    string s;cin >> s;
    if(n%2 == 1){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i=0;i<n/2;i++){
        if(s[i] != s[i+n/2]) ans++;
    }
    cout << ans << endl;
    return 0;
}
