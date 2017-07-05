#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;

// Union-Find
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
};


struct V {
    int id;
    ll x, y;
};

struct E {
    ll w;
    int s, t;
};

// 最小全域木 (Minimum spanning tree)
// ARC076D
struct MST {
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

int main() {
    int n;
    cin >> n;

    UF uf(n);
    vector<V> v(n);
    vector<E> e;

    for(int i=0;i<n;i++){
        ll x, y;
        cin >> x >> y;
        v[i] = {i, x, y};
    }

    // x sort
    sort(v.begin(), v.end(), [](V v1, V v2){
            return v1.x != v2.x ? v1.x < v2.x : v1.y < v2.y;
            });
    for(int i=0;i<n-1;i++){
        ll w = min(abs(v[i].x - v[i+1].x), abs(v[i].y - v[i+1].y));
        e.push_back({w, v[i].id, v[i+1].id});
    }

    // y sort
    sort(v.begin(), v.end(), [](V v1, V v2){
            return v1.y != v2.y ? v1.y < v2.y : v1.x < v2.x;
            });
    for(int i=0;i<n-1;i++){
        ll w = min(abs(v[i].x - v[i+1].x), abs(v[i].y - v[i+1].y));
        e.push_back({w, v[i].id, v[i+1].id});
    }

    // solve
    auto mst = MST::solve(n, e);

    ll ans = 0;
    for(auto v : mst){
        ans += v.w;
    }

    cout << ans << endl;

    return 0;
}
