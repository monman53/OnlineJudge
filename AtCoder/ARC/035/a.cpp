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
    string ans = "YES";
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '*') continue;
        if(s[n-i-1] == '*') continue;
        if(s[i] != s[n-i-1]) ans = "NO";
    }
    cout << ans << endl;
    return 0;
}
