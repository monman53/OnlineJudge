// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

struct E {
    int to, w;
};
 
using G = vector<vector<E>>;
 
template <typename T>
pair<vector<T>, vector<int>> dijkstra(G g, int s, T inf) {
    int n = g.size();
    vector<T> d(n, inf);
    vector<int> r(n, -1);
    d[s] = 0;
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto c = pq.top();pq.pop();
        if(d[c.second] < c.first) continue;
        for(auto e : g[c.second]){
            if(d[e.to] > d[c.second] + e.w){
                d[e.to] = d[c.second] + e.w;
                r[e.to] = c.second;
                pq.push({d[e.to], e.to});
            }
        }
    }
    return {d, r};
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, t;cin >> n >> m >> t;
    vector<int> a(n);
    inc(i, 0, n) cin >> a[i];
    G g(n), r(n);
    inc(i, 0, m){
        int a, b, c;cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
        r[b].push_back({a, c});
    }
    auto dg = dijkstra<LL>(g, 0, LLONG_MAX/3).fi;
    auto dr = dijkstra<LL>(r, 0, LLONG_MAX/3).fi;
    LL ans = 0;
    inc(i, 0, n){
        LL d = t-dg[i]-dr[i];
        if(d < 0) continue;
        ans = max(ans, d*a[i]);
    }
    cout << ans << endl;
    return 0;
}
