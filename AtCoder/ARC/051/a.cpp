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
    int x1, y1, r;cin >> x1 >> y1 >> r;
    int x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    x2 -= x1;y2 -= y1;
    x3 -= x1;y3 -= y1;

    string ans = "YES";
    if(x2 <= -r && y2 <= -r && x3 >= r && y3 >= r) ans = "NO";
    cout << ans << endl;

    ans = "YES";
    if(x2*x2+y2*y2 <= r*r &&
       x2*x2+y3*y3 <= r*r &&
       x3*x3+y2*y2 <= r*r &&
       x3*x3+y3*y3 <= r*r) ans = "NO";
    cout << ans << endl;
    return 0;
}
