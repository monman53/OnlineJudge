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
    int ans = 0;
    int x = 0;
    for(auto c : s){
        if(c == 'I'){
            x++;
        }else{
            x--;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}
