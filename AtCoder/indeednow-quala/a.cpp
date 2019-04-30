// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int f(int n){
    int ret = 0;
    while(n > 0){
        ret++;
        n /= 10;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int a, b;cin >> a >> b;
    cout << f(a)*f(b) << endl;
    return 0;
}
