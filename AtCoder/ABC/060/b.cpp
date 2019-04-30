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
    int a, b, c;cin >> a >> b >> c;
    for(int i=1;i<=b;i++){
        if(a*i%b == c){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
