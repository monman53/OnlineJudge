// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

LL cnt[2] = {0, 0};
vector<int> f;
vector<vector<int>> g;

bool dfs(int i, int n) {
    if(f[i] != -1){
        if(f[i] != n%2) return false;
        return true;
    }
    f[i] = n%2;
    cnt[n%2]++;
    bool ret = true;
    for(auto e : g[i]){
        ret &= dfs(e, n+1);
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);

    LL n;cin >> n;
    g.resize(n);
    f.resize(n, -1);
    int m;cin >> m;
    for(int i=0;i<m;i++){
        int a, b;cin >> a >> b;a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << (dfs(0, 0) ? cnt[0]*cnt[1] - m : n*(n-1)/2 - m) << endl;

    return 0;
}
