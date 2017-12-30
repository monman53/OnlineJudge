// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// Dijkstra {{{
// sからの距離dと経路復元用のr(rev)を返す
// ABC051D

struct E {
    int to, w;
};

using G = vector<vector<E>>;

template <typename T>
pair<vector<T>, vector<int>> dijkstra(G &g, int s, T inf) {
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
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    G g(n);
    for(int i=0;i<m;i++){
        int a, b, c;cin >> a >> b >> c;a--;b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int used[100][100];
    memset(used, 0, sizeof(used));
    for(int i=0;i<n;i++){
        auto p = dijkstra<int>(g, i, INF);
        auto d = p.first;
        auto r = p.second;
        for(int j=0;j<n;j++){
            if(i == j) continue;
            int c = j;
            while(r[c] != -1){
                used[c][r[c]] = 1;
                used[r[c]][c] = 1;
                c = r[c];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans += used[i][j];
        }
    }
    cout << m-ans << endl;
    return 0;
}
