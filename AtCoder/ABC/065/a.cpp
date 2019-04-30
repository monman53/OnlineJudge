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
    int x, a, b;cin >> x >> a >> b;
    if(b <= a) cout << "delicious" << endl;
    else if(b <= a+x) cout << "safe" << endl;
    else cout << "dangerous" << endl;
    return 0;
}
