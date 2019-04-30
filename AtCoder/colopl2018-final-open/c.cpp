// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
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
    SGT();
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

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<LL> a(n);
    inc(i, 0, n){
        cin >> a[i];
    }
    SGT<LL> sgt(a, LLONG_MAX/3, [](LL a, LL b){return min(a, b);});

    inc(i, 0, n){
        // r
        int l = i;
        int r = n;
        while(r-l>10){
            int ml = (l*2+r)/3;
            int mr = (l+r*2)/3;
            if(sgt.query(i, ml+1)+(i-ml)*(i-ml) < 
               sgt.query(i, mr+1)+(i-mr)*(i-mr)){
                r = mr;
            }else{
                l = ml;
            }
        }
        LL ansr = LLONG_MAX;
        inc(j, 0, 10){
            if(l+j<n){
                ansr = min(ansr, a[l+j]+(i-l-j)*(i-l-j));
            }
        }

        // l
        l = 0;
        r = i;
        while(r-l>10){
            int ml = (l*2+r)/3;
            int mr = (l+r*2)/3;
            if(sgt.query(ml, i+1)+(i-ml)*(i-ml) < 
               sgt.query(mr, i+1)+(i-mr)*(i-mr)){
                r = mr;
            }else{
                l = ml;
            }
        }
        LL ansl = LLONG_MAX;
        inc(j, 0, 10){
            if(l+j<n){
                ansl = min(ansl, a[l+j]+(i-l-j)*(i-l-j));
            }
        }

        cout << min(ansl, ansr) << endl;
    }

    return 0;
}
