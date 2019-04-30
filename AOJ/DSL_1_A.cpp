// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}
// data structure {{{

// Union-Find
// verified AOJ DSL_1_A
class UF {
    vector<int> p;  // parent
    vector<int> r;  // rank
public:
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
};

struct E {
    int s, t;
    int w;
};

// 最小全域木 (Minimum spanning tree)
// ARC076D
struct MST {
    // クラスカル法
    static vector<E> solve(int n, vector<E> e) {
        UF uf(n);
        vector<E> ret;
        sort(e.begin(), e.end(), [](E e1, E e2){
                return e1.w < e2.w;
                });
        for(auto ee : e){
            if(uf.find(ee.s) != uf.find(ee.t)){
                uf.unite(ee.s, ee.t);
                ret.push_back({ee.w, ee.s, ee.t});
            }
        }
        return ret;
    }
};
//}}}

int main() {
    int n, q;cin >> n >> q;
    UF uf(n);
    for(int i=0;i<q;i++){
        int com, x, y;cin >> com >> x >> y;
        if(com == 0){
            uf.unite(x, y);
        }else{
            if(uf.find(x) == uf.find(y)){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
