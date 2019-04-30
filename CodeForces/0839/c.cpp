// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

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
};
//}}}

G<int> g;

double dfs(int p, int i, int d){
    int n = g.e[i].size();
    double sum = 0;
    for(auto ee : g.e[i]){
        if(ee.to != p){
            sum += dfs(i, ee.to, d+1)+1.0;
        }
    }
    if(p == -1){
        return sum/double(n);
    }
    if(n == 1){
        return 0.0;
    }
    return sum/double(n-1);
}

int main() {
    int n;cin >> n;
    g = G<int>(n);
    if(n==1){
        printf("%.8lf\n", 0);
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int s, t;cin >> s >> t;s--;t--;
        g.add(s, t, 1);
        g.add(t, s, 1);
    }
    printf("%.8lf\n", dfs(-1, 0, 0));
    return 0;
}
