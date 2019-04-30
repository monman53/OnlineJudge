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
    string o, e;cin >> o >> e;
    int n = o.size()+e.size();
    for(int i=0;i<n;i++){
        if(i%2 == 0){
            cout << o[i/2];
        }else{
            cout << e[i/2];
        }
    }
    cout << endl;
    return 0;
}
