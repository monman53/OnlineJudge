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
    int m, n, N;cin >> m >> n >> N;
    int ans = N;
    while(N >= m){
        //cout << ans << endl;
        ans += N/m*n;
        int c = N%m;
        N = N/m*n;
        N += c;
    }
    cout << ans << endl;
    return 0;
}
