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
    for(int i=0;i<ALPHABET;i++){
        bool flag = true;
        for(auto c : s){
            if(c == 'a'+i) flag = false;
        }
        if(flag){
            cout << char('a'+i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
