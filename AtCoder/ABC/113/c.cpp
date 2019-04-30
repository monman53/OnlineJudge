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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    vector<int> p(m), y(m);
    vector<vector<int>> ans(n);
    inc(i, 0, m){
        cin >> p[i] >> y[i];
        p[i]--;
        ans[p[i]].pb(y[i]);
    }
    inc(i, 0, n) sort(ans[i].begin(), ans[i].end());
    inc(i, 0, m){
        printf("%06d%06d\n", p[i]+1, int(lower_bound(ans[p[i]].begin(), ans[p[i]].end(), y[i]) - ans[p[i]].begin() + 1));
    }

    return 0;
}
