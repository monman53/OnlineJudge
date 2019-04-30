// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int n;
G g;
int a[100], b[100];

int depth(int from, int to) {
    int mx = 1;
    for(auto next : g[to]){
        if(next == from) continue;
        mx = max(mx, depth(to, next)+1);
    }
    return mx;
}

int leaf(int from, int to) {
    int res = 0;
    int c = 0;
    for(auto next : g[to]){
        if(next == from) continue;
        c++;
        res += leaf(to, next);
    }
    if(c == 0){
        return 1;
    }else{
        return res;
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    inc(i, 0, n-1){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        g[b[i]].pb(a[i]);
        g[a[i]].pb(b[i]);
    }
    vector<pair<int, int>> ans;
    inc(i, 0, n-1){
        int d = max(depth(a[i], b[i]), depth(b[i], a[i]));
        int l = max(leaf(a[i], b[i]), leaf(b[i], a[i]));
        ans.pb({d, l});
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].fi << " " << ans[0].se*2 << endl;
    return 0;
}
