// data structure {{{

// Union-Find {{{
// O(a(n))
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
// Union-Find (short) {{{
struct UF_short {
    vector<int> p;  // parent

    UF_short(int n) {
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
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
        p[y] = p[x];
    }
}; // }}}
// 最小全域木 (Minimum spanning tree) {{{
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
// Segment tree (2D) {{{
// AOJ 1068
template<class T>
struct SGT2 {
    vector<T> dat;
    int h, w;
    T init;
    SGT2(){}
    SGT2(int h, int w, T init) {
        this->init = init;
        this->h = h;
        this->w = w;
        dat = vector<T>(h*w*8, init);
    }

    T update(int i, int j, T x, int k, int si, int sj, int ti, int tj) {
        if(i < si || ti <= i || j < sj || tj <= j) return dat[k];
        int di = ti-si;
        int dj = tj-sj;
        int ci = (si+ti)/2;
        int cj = (sj+tj)/2;
        if(di == 1 && dj == 1) return dat[k] = x;
        if(di < dj){
            T v0 = update(i, j, x, k*2+1, si, sj, ti, cj);
            T v1 = update(i, j, x, k*2+2, si, cj, ti, tj);
            return dat[k] = min(v0, v1);
        }else{
            T v0 = update(i, j, x, k*2+1, si, sj, ci, tj);
            T v1 = update(i, j, x, k*2+2, ci, sj, ti, tj);
            return dat[k] = min(v0, v1);
        }
    }
    T update(int i, int j, T x) {
        return update(i, j, x, 0, 0, 0, h, w);
    }

    T query(int ssi, int ssj, int tti, int ttj, int k, int si, int sj, int ti, int tj) {
        if(ti <= ssi || tti <= si || tj <= ssj || ttj <= sj) return init;
        if(ssi <= si && ti <= tti && ssj <= sj && tj <= ttj) return dat[k];
        int di = ti-si;
        int dj = tj-sj;
        int ci = (si+ti)/2;
        int cj = (sj+tj)/2;
        if(di < dj){
            T v0 = query(ssi, ssj, tti, ttj, k*2+1, si, sj, ti, cj);
            T v1 = query(ssi, ssj, tti, ttj, k*2+2, si, cj, ti, tj);
            return min(v0, v1);
        }else{
            T v0 = query(ssi, ssj, tti, ttj, k*2+1, si, sj, ci, tj);
            T v1 = query(ssi, ssj, tti, ttj, k*2+2, ci, sj, ti, tj);
            return min(v0, v1);
        }
    }
    T query(int si, int sj, int ti, int tj) {
        return query(si, sj, ti, tj, 0, 0, 0, h, w);
    }
};//}}}
// Binary Indexed Tree // {{{
struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) {
        bit.resize(n+1, 0);
        this->n = n;
    }
    int sum(int i) {
        int s = 0;
        while(i > 0){
            s += bit[i];
            // i & -i はiの最後の1のビット
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x) {
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

// 順列の転倒数 (1-indexed)
LL inv(vector<int> a) {
    int n = a.size();
    BIT bit(n);
    LL ans = 0;
    for(int j=0;j<n;j++){
        ans += j - bit.sum(a[j]);
        bit.add(a[j], 1);
    }
    return ans;
}
// }}}
//}}}
