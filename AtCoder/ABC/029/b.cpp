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
    int ans = 0;
    for(int i=0;i<12;i++){
        string s;cin >> s;
        for(auto c : s){
            if(c == 'r'){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
