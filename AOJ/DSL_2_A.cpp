// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// Segment tree {{{
// O(N) 構築
// O(log(N)) update, query
// verified AOJ DSL_2_A
template <typename T>
struct SGT {
    vector<T> v;
    int n;
    T init;
    function<T(T, T)> f;
    SGT(vector<T> a, T init, function<T(T, T)> f){
        int m = a.size();
        n = 1;
        while(n < m) n <<= 1;
        this->init = init;
        this->f = f;
        v.resize(2*n-1, init);
        for(int i=0;i<m;i++) v[n-1+i] = a[i];
        for(int i=n-2;i>=0;i--) v[i] = min(v[i*2+1], v[i*2+2]);
    }
    void update(int i, T x) {
        i += n-1;
        v[i] = x;
        while(i>0){
            i = (i-1)/2;
            v[i] = f(v[i*2+1], v[i*2+2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b) return v[k];
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return f(vl, vr);
    }
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, q;cin >> n >> q;
    vector<int> a(n, INT_MAX);
    SGT<int> sgt(a, INT_MAX, [](int a, int b){return min(a, b);});
    for(int i=0;i<q;i++){
        int c, x, y;cin >> c >> x >> y;
        if(c == 0) sgt.update(x, y);
        if(c == 1) cout << sgt.query(x, y+1) << endl;
    }
    return 0;
}
