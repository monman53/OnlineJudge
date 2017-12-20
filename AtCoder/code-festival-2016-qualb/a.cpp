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
    string s;cin >> s;
    string t = "CODEFESTIVAL2016";
    int ans = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(t[i] != s[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
