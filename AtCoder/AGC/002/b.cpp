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
    int n, m;cin >> n >> m;
    vector<bool> f(n, false);f[0] = true;
    vector<int> cnt(n, 1);
    for(int i=0;i<m;i++){
        int x, y;cin >> x >> y;x--;y--;
        if(f[x] == true) f[y] = true;
        cnt[x]--;
        if(cnt[x] == 0) f[x] = false;
        cnt[y]++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(f[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
