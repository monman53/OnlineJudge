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

vector<vector<int>> g;
vector<list<int>> ans[2];

int dfs(int from, int to) {
    int count = 0;
    for(auto next : g[to]){
        if(next == from) continue;
        dfs(to, next);
        count++;
    }
    ans[0][to] = {1};
    ans[1][to] = {1};
    if(count == 0){
        return 1;
    }else{
        return count+1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    g.resize(n+1);
    ans[0].resize(n+1);
    ans[1].resize(n+1);

    for(int i=1;i<=n;i++){
        int p;cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    dfs(-1, 0);

    return 0;
}
