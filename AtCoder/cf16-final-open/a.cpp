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
    int h, w;cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            string s;cin >> s;
            if(s == "snuke"){
                cout << char('A'+j) << i+1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
