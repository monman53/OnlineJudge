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
    sort(s.begin(), s.end());
    if(s == "ahooy"){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
