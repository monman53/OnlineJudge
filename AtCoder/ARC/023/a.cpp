// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int f(int y, int m, int d) {
    if(m == 1){
        y--;
        m = 13;
    }
    if(m == 2){
        y--;
        m = 14;
    }
    return 365*y + y/4 - y/100 + y/400 + 306*(m+1)/10 + d - 429;
}

int main() {
    std::ios::sync_with_stdio(false);
    int y, m, d;cin >> y >> m >> d;
    cout << f(2014, 5, 17) - f(y, m, d) << endl;
    return 0;
}
