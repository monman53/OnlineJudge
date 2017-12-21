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
    map<char, char> m;
    m['O'] = '0';
    m['D'] = '0';
    m['I'] = '1';
    m['Z'] = '2';
    m['S'] = '5';
    m['B'] = '8';
    for(int i=0;i<10;i++){
        m['0'+i] = '0'+i;
    }

    string s;cin >> s;
    for(auto &c : s){
        c = m[c];
    }
    cout << s << endl;
    return 0;
}
