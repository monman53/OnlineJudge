// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}


struct E {
    LL to, w;
};

vector<LL> x;
vector<vector<E>> g;
string ans = "Yes";

void dfs(LL i, LL now) {
    if(x[i] != LLONG_MAX){
        if(now != x[i]){
            ans = "No";
        }
    }else{
        x[i] = now;
        for(auto e : g[i]){
            dfs(e.to, now+e.w);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, m;cin >> n >> m;
    x.resize(n, LLONG_MAX);
    g.resize(n);
    inc(i, 0, m){
        LL l, r, d;cin >> l >> r >> d;
        l--;r--;
        g[l].pb({r, d});
        g[r].pb({l, -d});
    }
    inc(i, 0, n){
        if(x[i] != LLONG_MAX) continue;
        dfs(i, 0);
    }

    cout << ans << endl;
    return 0;
}
