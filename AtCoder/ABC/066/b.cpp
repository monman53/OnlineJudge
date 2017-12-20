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
    for(int i=0;i<n;i++){
        s.pop_back();
        int c = s.size()/2;
        if(s.substr(0, c) == s.substr(c)){
            cout << s.size() << endl;
            return 0;
        }
    }
    return 0;
}
