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

int solve(int n, vector<int> c, vector<int> a) {
    int x[2] = {0, 0};
    int r[2][2000];

    inc(i, 0, n*2){
        r[c[i]][a[i]] = i;
    }

    vector<int> v(n*2);
    inc(i, 0, n*2) v[i] = 0;
    SGT<int> sgt(v, 0, [](int a, int b){return a+b;});

    int ans = 0;

    inc(i, 0, n*2){
        if(c[i] == -1) continue;
        if(x[c[i]] == a[i]){
            x[c[i]]++;
            continue;
        }
        //cout << "#" << i << endl;
        inc(j, x[c[i]], a[i]){
            int k = r[c[i]][j];
            int d = k - i - sgt.query(i+1, k+1);
            ans += d;
            //cout << k << " " << d << endl;
            sgt.update(k, 1);
            c[k] = -1;
        }
        //cout << i << " " << ans << endl;
        x[c[i]]=a[i]+1;
    }

    return ans;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> c(n*2);
    vector<int> a(n*2);
    inc(i, 0, n*2){
        char cc; cin >> cc;
        c[i] = (cc == 'B' ? 0 : 1);
        cin >> a[i];a[i]--;
    }

    int aa = solve(n, c, a);
    //cout << solve(n, c, a) << endl;

    reverse(c.begin(), c.end());
    reverse(a.begin(), a.end());
    inc(i, 0, n*2){
        a[i] = n-a[i]-1;
        //cout << c[i] << " " << a[i] << endl;
    }

    int bb = solve(n, c, a);
    //cout << solve(n, c, a) << endl;
    

    cout << min(aa, bb) << endl;

    return 0;
}
