// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int n, W;
vector<int> w, v;
vector<vector<int>> vv(4);

int solve(int k, int cap, int ans) {
    if(k == 4) return ans;
    int ret = solve(k+1, cap, ans);
    int sum = 0;
    for(int i=1;i<=min(cap/(w[0]+k), (int)vv[k].size());i++){
        sum += vv[k][i-1];
        ret = max(ret, solve(k+1, cap - i*(w[0]+k), ans+sum));
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> W;
    w.resize(n);
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
        vv[w[i]-w[0]].push_back(v[i]);
    }
    for(int i=0;i<4;i++){
        sort(vv[i].begin(), vv[i].end());
        reverse(vv[i].begin(), vv[i].end());
    }

    cout << solve(0, W, 0) << endl;
    return 0;
}
