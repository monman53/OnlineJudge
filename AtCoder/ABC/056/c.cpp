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
    LL x;cin >> x;
    for(LL i=1LL;;i++){
        if(x <= i*(i+1)/2){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
