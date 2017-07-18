// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}
// graph {{{

// グラフ {{{
template<class T>
struct E {
    int to;
    T w;
};

template<class T>
struct ES {
    int from;
    int to;
    T w;
};

template<class T>
struct G {
    vector<vector<E<T>>> e;
    int n;
    G(int _n) {
        n = _n;
        e.resize(n);
    }
    void add(int i, int j, T w) {
        assert(i >= 0 && i < n && j >= 0 && j < n);
        e[i].push_back({j, w});
    }
    vector<ES<T>> getES() {
        vector<ES<T>> ret;
        for(int i=0;i<n;i++){
            for(auto ee : e[i]){
                ret.push_back({i, ee.to, ee.w});
            }
        }
        return ret;
    }
};//}}}

// 負辺無し単一始点最短路 (Dijkstra) {{{
// O(ElogV)
// verified AOJ GRL_1_A
template<class T>
vector<T> solveDijkstra(G<T> g, int s) {
    vector<T> d(g.n, INF);
    priority_queue<PTI<T>, vector<PTI<T>>, greater<PTI<T>>> pq;
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto c = pq.top();pq.pop();
        int ci = c.second;
        int cd = c.first;
        if(cd > d[ci]) continue;
        for(auto e : g.e[ci]){
            if(cd + e.w < d[e.to]){
                d[e.to] = cd + e.w;
                pq.push({cd + e.w, e.to});
            }
        }
    }
    return d;
}//}}}

// 重みなし単一始点最短路 (幅優先探索) {{{
// O(V)
// ARC078D
template<class T>
vector<int> solveBFS(G<T> g, int s) {
    vector<int> d(g.n, INF);
    queue<PII> q;
    d[s] = 0;
    q.push({0, s});
    while(!q.empty()){
        auto c = q.front();q.pop();
        int ci = c.second;
        int cd = c.first;
        if(cd > d[ci]) continue;
        for(auto e : g.e[ci]){
            if(cd + e.w < d[e.to]){
                d[e.to] = cd + 1;
                q.push({cd + 1, e.to});
            }
        }
    }
    return d;
}//}}}

// 負辺有り単一始点最短路 (Bellman Ford) {{{
// **sから到達できる**負閉路が存在する場合は，返り値のfirstがfalse
// (到達できない負閉路が存在しても，その負閉路上のノードのコストはINF)
// O(EV)
// verified AOJ GRL_1_B
template<class T>
pair<bool, vector<T>> solveBF(G<T> g, int s) {
    vector<T> d(g.n, INF);
    d[s] = 0;
    auto es = g.getES();
    int count = 0;
    while(true){
        bool update = false;
        for(auto e : es){
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.w){
                d[e.to] = d[e.from] + e.w;
                update = true;
            }
        }
        if(!update) break;
        if(++count > g.n) return {false, {}};
    }
    return {true, d};
}//}}}

// 負閉路存在判定 (Bellman Ford) {{{
// O(VE)
// verified AOJ GRL_1_C
template<class T>
bool hasNEdge(G<T> g) {
    vector<T> d(g.n, 0);
    int count = 0;
    for(int i=0;i<int(g.e.size());i++){
        for(int j=0;j<int(g.e.size());j++){
            for(auto e : g.e[j]){
                if(d[e.to] > d[j] + e.w){
                    d[e.to] = d[j] + e.w;
                    if(i == g.n-1){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}//}}}

// 全点対最短路ワーシャル・フロイド法 {{{
// INFのとり方に注意．大きすぎるとオーバーフローする
// O(V^3)
// verified AOJ GRL_1_C
template<class T>
vector<vector<T>> solveWF(G<T> g) {
    vector<vector<T>> d(g.n, vector<T>(g.n, INF));
    auto es = g.getES();
    for(auto e : es) d[e.from][e.to] = e.w;
    for(int i=0;i<g.n;i++){
        d[i][i] = 0;
    }
    for(int k=0;k<g.n;k++){
        for(int i=0;i<g.n;i++){
            for(int j=0;j<g.n;j++){
                if(d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}// }}}
//}}}

int main() {
    int n;cin >> n;
    G<int> g(n);
    for(int i=0;i<n-1;i++){
        int a, b;cin >> a >> b;
        a--;b--;
        g.add(a, b, 1);
        g.add(b, a, 1);
    }
    auto fennec = solveBFS(g, 0);
    auto snuke  = solveBFS(g, n-1);
    int count = 0;
    for(int i=0;i<n;i++){
        if(fennec[i] <= snuke[i]){
            count++;
        }
    }
    if(count > n/2){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
    return 0;
}
