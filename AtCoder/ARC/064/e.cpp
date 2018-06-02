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

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

struct E {
    int to;
    double w;
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
    cin.tie(0);ios::sync_with_stdio(false);
    vector<double> x, y, r;
    double sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    x.pb(sx);y.pb(sy);r.pb(0);
    x.pb(tx);y.pb(ty);r.pb(0);
    int n;cin >> n;
    inc(i, 0, n){
        double xx, yy, rr;
        cin >> xx >> yy >> rr;
        x.pb(xx);y.pb(yy);r.pb(rr);
    }
    n += 2;
    
    G g(n);

    inc(i, 0, n){
        inc(j, 0, n){
            if(i == j) continue;
            double dx = x[i]-x[j];
            double dy = y[i]-y[j];
            double d = max(0.0, sqrt(dx*dx + dy*dy) - r[i] - r[j]);

            g[i].pb({j, d});
        }
    }

    auto ans = dijkstra<double>(g, 0, 1e20).first[1];

    printf("%.12lf\n", ans);

    return 0;
}
