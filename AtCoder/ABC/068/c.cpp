// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    vector<bool> ok(n, false);
    string ans = "IMPOSSIBLE";
    for(int i=0;i<m;i++){
        int a, b;cin >> a >> b;a--;b--;
        int c = (a == 0 ? b : (b == n-1 ? a : -1));

        if(c == -1) continue;

        if(ok[c])
            ans = "POSSIBLE";
        else
            ok[c] = true;
    }
    cout << ans << endl;
    return 0;
}
