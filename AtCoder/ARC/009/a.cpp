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
    int n;cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int a, b;cin >> a >> b;
        ans += a*b;
    }
    cout << int(ans*1.05) << endl;
    return 0;
}
