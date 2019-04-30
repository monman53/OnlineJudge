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
    LL to, w;
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


// Segment tree {{{
// O(N) 構築
// O(log(N)) update, query
// verified AOJ DSL_2_A
template <typename T>
struct SGT {
    vector<T> v;
    int n;
    T init;
    function<T(T, T)> f;
    SGT(vector<T> a, T init, function<T(T, T)> f){
        int m = a.size();
        n = 1;
        while(n < m) n <<= 1;
        this->init = init;
        this->f = f;
        v.resize(2*n-1, init);
        for(int i=0;i<m;i++) v[n-1+i] = a[i];
        for(int i=n-2;i>=0;i--) v[i] = f(v[i*2+1], v[i*2+2]);
    }
    void update(int i, T x) {
        i += n-1;
        v[i] = x;
        while(i>0){
            i = (i-1)/2;
            v[i] = f(v[i*2+1], v[i*2+2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b) return v[k];
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return f(vl, vr);
    }
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};
// }}}


int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n, m, s, t;cin >> n >> m >> s >> t;
    s--;t--;
    G gs(n), gt(n);
    inc(i, 0, m){
        LL u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;v--;
        gs[u].pb({v, a});
        gs[v].pb({u, a});
        gt[u].pb({v, b});
        gt[v].pb({u, b});
    }
    auto ds = dijkstra<LL>(gs, s, LLONG_MAX).fi;
    auto dt = dijkstra<LL>(gt, t, LLONG_MAX).fi;

    vector<LL> v(n);
    LL sunuke = 1e15;
    inc(i, 0, n){
        v[i] = sunuke-(ds[i]+dt[i]);
    }
    SGT<LL> sgt(v, 0, [](LL a, LL b){return max(a, b);});

    inc(i, 0, n){
        cout << sgt.query(i, n) << endl;
    }
    return 0;
}
