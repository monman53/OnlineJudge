// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

vector<vector<int>> g;

string ans = "Yes";

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    g.resize(n);
    inc(i, 0, n-1){
        int p;cin >> p;p--;
        g[p].push_back(i+1);
    }
    inc(i, 0, n){
        if((int)g[i].size() == 0) continue;
        int cnt = 0;
        for(auto next : g[i]){
            if((int)g[next].size() == 0) cnt++;
        }
        if(cnt < 3) ans = "No";
    }
    cout << ans << endl;
    return 0;
}
