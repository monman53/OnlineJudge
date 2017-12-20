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
    if(a == 1) a = 14;
    if(b == 1) b = 14;
    string ans = "";
    if(a > b) ans = "Alice";
    if(a == b) ans = "Draw";
    if(a < b) ans = "Bob";
    cout << ans << endl;
    return 0;
}
