// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
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

// Union-Find // {{{
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

// 最小全域木 (Minimum spanning tree) // {{{
// ARC076D

struct E {
    int s, t;
    int w;
};

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
};// }}}

// Segment tree // {{{
// verified AOJ DSL_2_B
template <typename T>
struct SGT {
    vector<T> dat;
    int n;
    T init;
    SGT(int n, T init) {
        this->n     = n;
        this->init  = init;
        dat = vector<T>(4*n, init);
    }
    T update(int i, T x, int k, int l, int r) {
        if(i < l || r <= i) return dat[k];
        if(l+1 == r) return dat[k] += x;
        T vl = update(i, x, k*2+1, l, (l+r)/2);
        T vr = update(i, x, k*2+2, (l+r)/2, r);
        return dat[k] = vl + vr;
    }
    // [a, b)の所望の値．[l, r)はノードkに対応する区間．
    T find(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b) return dat[k];

        T vl = find(a, b, k*2+1, l, (l+r)/2);
        T vr = find(a, b, k*2+2, (l+r)/2, r);
        return vl + vr;
    }
    // interfaces
    void update(int i, T x) {
        update(i, x, 0, 0, n);
    }
    T find(int a, int b) {
        return find(a, b, 0, 0, n);
    }
};//}}}
//}}}

int main() {
    int n, q;cin >> n >> q;
    SGT<ll> rsq(n, 0);
    for(int i=0;i<q;i++){
        ll com, x, y;cin >> com >> x >> y;
        if(com == 0){
            x--;
            rsq.update(x, y);
        }else{
            x--;y--;
            printf("%lld\n", rsq.find(x, y+1));
        }
    }
    return 0;
}
