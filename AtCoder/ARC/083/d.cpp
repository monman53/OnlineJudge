// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         LLONG_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;
using P   = pair<LL, pair<int, int>>;
// }}}
// graph {{{
struct E {
    int from;
    int to;
    LL w;
};
template<class T>
struct G {
    // 辺
    int n;  // 頂点数
    vector<vector<E>> e;// 隣接リスト
    // コンストラクタ
    G(){}
    G(int n) {
        this->n = n;
        e.resize(n);
    }
    // 辺の追加
    void add(int i, int j, T w) {
        e[i].push_back({i, j, w});
    }
    // 全辺の取得
    vector<E> getES() {
        vector<E> ret;
        for(int i=0;i<n;i++){
            for(auto ee : e[i]){
                ret.push_back(ee);
            }
        }
        return ret;
    }
    // 全点対最短路ワーシャル・フロイド法 {{{
    // INFのとり方に注意．大きすぎるとオーバーフローする
    // O(V^3)
    // verified AOJ GRL_1_C
    vector<vector<T>> solveWF() {
        vector<vector<T>> d(n, vector<T>(n, INF));
        auto es = getES();
        for(auto e : es) d[e.from][e.to] = e.w;
        for(int i=0;i<n;i++){
            d[i][i] = 0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(d[i][k] == INF || d[k][j] == INF) continue;
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        return d;
    }// }}}
};
//}}}
// Union-Find {{{
// verified AOJ DSL_1_A
struct UF {
    vector<int> p;  // parent
    vector<int> r;  // rank

    UF(int n) {
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
            r[i] = 1;
        }
    }

    int find(int x) {
        if(x == p[x]){
            return x;
        }else{
            return p[x] = find(p[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(r[x] < r[y]){
            p[x] = y;
        }else{
            p[y] = x;
            if(r[x] == r[y]){
                r[x]++;
            }
        }
    }
}; // }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    G<LL> g(n);
    int a[300][300];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            g.add(i, j, a[i][j]);
        }
    }
    auto ans = g.solveWF();
    LL sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j] != a[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    UF uf(n);
    auto es = g.getES();
    priority_queue<P> pq;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({-a[i][j], {i, j}});
        }
    }
    LL aans = 0;
    vector<vector<LL>> d(n, vector<LL>(n, INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j] = 0;
        }
    }
    for(int i=0;i<n-1;i++){
        auto c = pq.top();pq.pop();
        LL w = -c.first;
        int f = c.second.first;
        int t = c.second.second;
        d[f][t] = w;
        d[t][f] = w;
        aans += w;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][f] == INF || d[t][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][f]+w+d[t][j]);
                d[i][j] = min(d[i][j], d[i][t]+w+d[f][j]);
            }
        }
    }
    while(!pq.empty()){
        auto c = pq.top();pq.pop();
        LL w = -c.first;
        int f = c.second.first;
        int t = c.second.second;
        if(a[f][t] == w) continue;
        d[f][t] = w;
        d[t][f] = w;
        cout << w << endl;
        aans += w;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][f] == INF || d[t][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][f]+w+d[t][j]);
                d[i][j] = min(d[i][j], d[i][t]+w+d[f][j]);
            }
        }
    }
    printf("%lld\n", aans);
    return 0;
}
