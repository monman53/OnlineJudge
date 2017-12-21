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
    string ans = "";
    for(auto c : s){
        if('0' <= c && c <= '9'){
            ans += c;
        }
    }
    cout << stoi(ans) << endl;
    return 0;
}
