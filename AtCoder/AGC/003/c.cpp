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
    int n;cin >> n;
    vector<int> a(n);
    inc(i, 0, n) cin >> a[i];

    auto b = compress(a);

    int ans = 0;
    inc(i, 0, n){
        if(i%2 != b[i]%2) ans++;
    }
    cout << ans/2 << endl;
    return 0;
}
