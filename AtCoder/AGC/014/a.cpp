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
    if(a%2 == 1 || b%2 == 1 || c%2 == 1){
        cout << 0 << endl;
        return 0;
    }

    if(a == b && b == c && c == a){
        cout << -1 << endl;
        return 0;
    }

    int count = 0;
    while(a%2 == 0 && b%2 == 0 && c%2 == 0){
        count++;
        int na = b/2 + c/2;
        int nb = c/2 + a/2;
        int nc = a/2 + b/2;
        a = na;
        b = nb;
        c = nc;
    }

    cout << count << endl;

    return 0;
}
