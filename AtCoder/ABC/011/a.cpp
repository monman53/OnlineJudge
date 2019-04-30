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
    for(auto &c : s){
        if(c < 'a' || 'z' < c){
            c = 'a' + c - 'A';
        }
    }
    s[0] = 'A' + s[0] - 'a';
    cout << s << endl;
    return 0;
}
