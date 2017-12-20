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
    string ans = "Impossible";
    if(a%3 == 0) ans = "Possible";
    if(b%3 == 0) ans = "Possible";
    if((a+b)%3 == 0) ans = "Possible";
    cout << ans << endl;
    return 0;
}
