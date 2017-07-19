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
template<class T>
class G {
    // 辺
    struct E {
        int from;
        int to;
        T w;
    };
    int n;  // 頂点数
    vector<vector<E>> e;// 隣接リスト
public:
    // コンストラクタ
    G(int _n) {
        n = _n;
        e.resize(n);
    }
    // 辺の追加
    void add(int i, int j, T w) {
        assert(i >= 0 && i < n && j >= 0 && j < n);
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
    // 負辺無し単一始点最短路 (Dijkstra) {{{
    // O(ElogV)
    // verified AOJ GRL_1_A
    vector<T> solveDijkstra(int s) {
        vector<T> d(n, INF);
        priority_queue<PTI<T>, vector<PTI<T>>, greater<PTI<T>>> pq;
        d[s] = 0;
        pq.push({0, s});
        while(!pq.empty()){
            auto c = pq.top();pq.pop();
            int ci = c.second;
            int cd = c.first;
            if(cd > d[ci]) continue;
            for(auto e : e[ci]){
                if(cd + e.w < d[e.to]){
                    d[e.to] = cd + e.w;
                    pq.push({cd + e.w, e.to});
                }
            }
        }
        return d;
    }//}}}
    // 単一始点最短路 (幅優先探索) {{{
    // 重みが一様であるか，グラフが木であるときに有効
    // O(V)
    // ARC078D
    vector<T> solveBFS(int s) {
        vector<T> d(n, INF);
        queue<PII> q;
        d[s] = 0;
        q.push({0, s});
        while(!q.empty()){
            auto c = q.front();q.pop();
            int ci = c.second;
            int cd = c.first;
            if(cd > d[ci]) continue;
            for(auto ee : e[ci]){
                if(cd + ee.w < d[ee.to]){
                    d[ee.to] = cd + ee.w;
                    q.push({cd + ee.w, ee.to});
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
    pair<bool, vector<T>> solveBF(int s) {
        vector<T> d(n, INF);
        d[s] = 0;
        auto es = getES();
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
            if(++count > n) return {false, {}};
        }
        return {true, d};
    }//}}}
    // 負閉路存在判定 (Bellman Ford) {{{
    // O(VE)
    // verified AOJ GRL_1_C
    bool hasNEdge() {
        vector<T> d(n, 0);
        int count = 0;
        for(int i=0;i<int(e.size());i++){
            for(int j=0;j<int(e.size());j++){
                for(auto ee : e[j]){
                    if(d[ee.to] > d[j] + ee.w){
                        d[ee.to] = d[j] + ee.w;
                        if(i == n-1){
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
    // 木の最遠点 {{{
    // グラフが木でない時，負辺が存在するときの動作は未定義
    // O(V)
    T treeFarthest(int s) {
        auto v = solveBFS(s);
        int id = 0;
        T mmax = 0;
        for(int i=0;i<(int)v.size();i++){
            if(mmax < v[i]){
                mmax = v[i];
                id = i;
            }
        }
        return id;
    }// }}}
    // 木の半径 {{{
    // グラフが木でない時，負辺が存在するときの動作は未定義
    // O(V)
    // verified AOJ GRL_5_A
    T treeDiameter() {
        int x = treeFarthest(0);
        int y = treeFarthest(x);
        auto v = solveBFS(x);
        return v[y];
    }// }}}
    // 木の(各点における)高さ {{{
    // O(V)
    // verified AOJ GRL_5_B
    vector<T> treeHeight() {
        int x = treeFarthest(0);
        int y = treeFarthest(x);
        auto vx = solveBFS(x);
        auto vy = solveBFS(y);
        vector<T> h(n);
        for(int i=0;i<n;i++){
            h[i] = max(vx[i], vy[i]);
        }
        return h;
    }// }}}
};
// }}}

int main() {
    int n;cin >> n;
    G<int> g(n);
    for(int i=0;i<n-1;i++){
        int s, t, w;cin >> s >> t >> w;
        g.add(s, t, w);
        g.add(t, s, w);
    }
    auto h = g.treeHeight();
    for(auto hh : h){
        cout << hh << endl;
    }
    return 0;
}
