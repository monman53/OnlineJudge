// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
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
        for(int i=n-2;i>=0;i--) v[i] = f(v[i*2+1], v[i*2+2]);
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

// 座標圧縮 {{{
// O(N*log(N))
template <typename T>
vector<int> compress(vector<T> v){
    int n = v.size();
    vector<int> res(n);

    auto u = v;
    sort(u.begin(), u.end());
    map<T, int> m;

    T b = u[0];
    int now = 0;
    inc(i, 0, n){
        if(b != u[i]) now++;
        m[u[i]] = now;
        b = u[i];
    }

    inc(i, 0, n){
        res[i] = m[v[i]];
    }

    return res;
}// }}}


int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL n;cin >> n;
    LL k;cin >> k;
    vector<LL> a(n);
    inc(i, 0, n) cin >> a[i];

    vector<LL> b(n+1, 0);
    inc(i, 0, n){
        b[i+1] = b[i] + a[i];
    }
    inc(i, 0, n+1){
        b[i] -= i*k;
    }

    auto c = compress(b);
    //inc(i, 0, n+1){
        //cout << b[i] << endl;
    //}
    //cout << endl;
    //inc(i, 0, n+1){
        //cout << c[i] << endl;
    //}

    vector<LL> cnt(n+1, 0);
    SGT<LL> sgt(cnt, 0, [](LL a, LL b){return a+b;});

    LL ans = 0;

    inc(i, 0, n+1){
        ans += sgt.query(0, c[i]+1);

        auto d = sgt.query(c[i], c[i]+1);
        sgt.update(c[i], d+1);
    }

    printf("%lld\n", ans);

    return 0;
}
