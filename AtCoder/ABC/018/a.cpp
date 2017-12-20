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
    if(a > b && b > c) cout << "1\n2\n3" << endl;
    if(a > c && c > b) cout << "1\n3\n2" << endl;
    if(b > a && a > c) cout << "2\n1\n3" << endl;
    if(c > a && a > b) cout << "2\n3\n1" << endl;
    if(b > c && c > a) cout << "3\n1\n2" << endl;
    if(c > b && b > a) cout << "3\n2\n1" << endl;
    return 0;
}
