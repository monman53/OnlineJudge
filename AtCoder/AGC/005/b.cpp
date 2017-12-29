// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

template <typename T>
struct SGT {
    vector<T> v;
    int n;
    T init;
    function<T(T, T)> f;
    SGT(vector<T> a, T init, function<T(T, T)> f){
        for(n=1;n<a.size();) n *= 2;
        this->init = init;
        this->f = f;
        v.resize(2*n-1, init);
    }
    T update(int i, T x, int k, int l, int r) {
        if(i < l || r <= i) return v[k];
        if(l+1 == r) return v[k] = x;
        T vl = update(i, x, k*2+1, l, (l+r)/2);
        T vr = update(i, x, k+2+2, (l+r)/2, r);
        return v[k] = f(vl, vr);
    }
    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b) return v[k];
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return f(vl, vr);
    }
    T update(int i, T x) {
        return update(i, x, 0, 0, n);
    }
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    return 0;
}
