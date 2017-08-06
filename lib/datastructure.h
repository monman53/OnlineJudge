// data structure {{{

// Union-Find {{{
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
// verified AOJ DSL_2_{A,B}
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
    T query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return init;
        if(a <= l && r <= b) return dat[k];

        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return vl + vr;
    }
    // interfaces
    T update(int i, T x) {
        update(i, x, 0, 0, n);
    }
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};//}}}
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
//}}}
