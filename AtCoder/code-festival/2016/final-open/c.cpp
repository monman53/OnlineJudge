// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

struct E {
    int to, w;
};
 
using G = vector<vector<E>>;
 
template <typename T>
pair<vector<T>, vector<int>> dijkstra(G g, int s, T inf) {
    int n = g.size();
    vector<T> d(n, INF);
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
    int n, m;cin >> n >> m;
    G g(n+m);
    for(int i=0;i<n;i++){
        int k;cin >> k;
        for(int j=0;j<k;j++){
            int l;cin >> l;l--;
            g[i].push_back({n+l, 1});
            g[n+l].push_back({i, 1});
        }
    }
    auto p = dijkstra(g, 0, INF);
    string ans = "YES";
    for(int i=0;i<n;i++){
        int d = p.first[i];
        if(d == INF) ans = "NO";
    }
    cout << ans << endl;
    return 0;
}
