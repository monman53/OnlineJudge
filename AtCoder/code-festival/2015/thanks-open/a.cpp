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
    int a, b;cin >> a >> b;
    if(a*b < 0){
        cout << abs(a)*2+abs(b)*2 << endl;
    }else{
        cout << max(abs(a), abs(b))*2 << endl;
    }
    return 0;
}
