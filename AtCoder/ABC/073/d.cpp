// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}


// graph {{{
template<class T>
struct G {
    // 辺
    struct E {
        int from;
        int to;
        T w;
    };
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

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, R;cin >> n >> m >> R;
    G<int> g(n);
    vector<int> r(R);
    for(int i=0;i<R;i++){
        cin >> r[i];
        r[i]--;
    }
    for(int i=0;i<m;i++){
        int a, b, c;cin >> a >> b >> c;a--;b--;
        g.add(a, b, c);
        g.add(b, a, c);
    }

    auto dist = g.solveWF();

    sort(r.begin(), r.end());
    int ans = INT_MAX;
    do{
        int d = 0;
        for(int i=1;i<R;i++){
            d += dist[r[i-1]][r[i]];
        }
        ans = min(ans, d);
    }while(next_permutation(r.begin(), r.end()));
    cout << ans << endl;
    return 0;
}
