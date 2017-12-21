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
    int n, l;cin >> n >> l;
    string s;cin >> s;
    int now = 1;
    int ans = 0;
    for(auto c : s){
        if(c == '+'){
            now++;
        }else{
            now--;
        }
        if(now > l){
            ans++;
            now = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
