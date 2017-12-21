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
    string s, t;cin >> s >> t;
    for(int i=n;i>=0;i--){
        if(s.substr(n-i, i) == t.substr(0, i)){
            cout << i + 2*(n-i) << endl;
            return 0;
        }
    }
    return 0;
}
