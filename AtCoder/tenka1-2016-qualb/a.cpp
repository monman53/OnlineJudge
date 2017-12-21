// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int f(int n) {
    return (n*n+4)/8;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout << f(f(f(20))) << endl;
    return 0;
}
