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
    vector<vector<pair<int, int>>> g(n);
    inc(i, 0, m){
        int p, q, c;cin >> p >> q >> c;
        p--;q--;
        g[p].pb({q, c});
        g[q].pb({p, c});
    }
    queue<pair<int, int>> q;
    vector<int> d(n, INF);
    set<pair<int, int>> kita;
    q.push({0, -1});
    d[0] = 0;
    while(!q.empty()){
        //int dd = q.front().fi;
        int i = q.front().fi;
        int c = q.front().se;
        q.pop();
        if(kita.find({i, c}) != kita.end()) continue;
        kita.insert({i, c});
        //if(dd > d[i]) continue;
        //d[i] = dd;
        //d[i] = min(d[i], dd);
        for(auto ne : g[i]){
            int nd = d[i]+(ne.se == c ? 0 : 1);
            if(d[ne.fi] < nd) continue;
            d[ne.fi] = nd;
            q.push({ne.fi, ne.se});
        }
    }
    cout << (d[n-1] == INF ? -1 : d[n-1]) << endl;
    return 0;
}
