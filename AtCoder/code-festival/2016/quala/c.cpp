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
    int n = s.size();
    int k;cin >> k;
    for(auto &c : s){
        int m = 'z'-c+1;
        if(c == 'a') continue;
        if(m <= k){
            c = 'a';
            k -= m;
        }
    }
    s[n-1] = 'a' + (s[n-1]-'a'+k)%26;
    cout << s << endl;
    return 0;
}
