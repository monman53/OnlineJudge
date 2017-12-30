// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    int ans = 0;
    for(auto c : s){
        switch(c){
            case '1':
            case '3':
            case '5':
            case '7':
            case '9':
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ans++;
                break;
            default:
                break;
        }
    }
    cout << ans << endl;
    return 0;
}
