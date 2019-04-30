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
    map<char, char> m;
    m['b'] = 'd';
    m['d'] = 'b';
    m['p'] = 'q';
    m['q'] = 'p';
    int n = s.size();
    string ans = "Yes";
    for(int i=0;i<n;i++){
        if(m[s[i]] != s[n-i-1]) ans = "No";
    }
    cout << ans << endl;
    return 0;
}
