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
    string a, b, c;cin >> a >> b >> c;
    cout << char(a[0]-'a'+'A') << char(b[0]-'a'+'A') << char(c[0]-'a'+'A') << endl;
    return 0;
}
