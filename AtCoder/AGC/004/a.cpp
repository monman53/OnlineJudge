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
    LL a, b, c;cin >> a >> b >> c;
    if(a%2 == 0 || b%2 == 0 || c%2 == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << min({a*b, b*c, c*a}) << endl;
    return 0;
}
