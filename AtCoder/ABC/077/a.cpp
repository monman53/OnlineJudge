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
    char c[2][3];
    for(int i=0;i<2;i++){
        string s;cin >> s;
        for(int j=0;j<3;j++){
            c[i][j] = s[j];
        }
    }

    if(c[0][0] == c[1][2] && c[0][1] == c[1][1] && c[0][2] == c[1][0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
