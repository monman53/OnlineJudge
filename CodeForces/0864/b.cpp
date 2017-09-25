// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    string s;cin >> s;
    set<char> sset;
    int ans = 0;
    for(int i=0;i<n;i++){
        char c = s[i];
        if('A' <= c && c <= 'Z'){
            ans = max(ans, int(sset.size()));
            sset.clear();
        }else{
            sset.insert(c);
        }
    }
    ans = max(ans, int(sset.size()));
    cout << ans << endl;
    return 0;
}
