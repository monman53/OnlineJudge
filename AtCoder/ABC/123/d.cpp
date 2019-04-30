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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL x, y, z;cin >> x >> y >> z;
    LL k;cin >> k;
    LL a[1000], b[1000], c[1000];
    inc(i, 0, x) cin >> a[i];
    inc(i, 0, y) cin >> b[i];
    inc(i, 0, z) cin >> c[i];
    sort(a, a+x);reverse(a, a+x);
    sort(b, b+y);reverse(b, b+y);
    sort(c, c+z);reverse(c, c+z);
    vector<LL> v;
    inc(i, 0, x){
        inc(j, 0, y){
            v.pb(a[i]+b[j]);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<LL> w;
    inc(i, 0, min(k, x*y)){
        w.pb(v[i]);
        //cout << v[i] << endl;
    }
    vector<LL> ans;
    inc(i, 0, min(k, x*y)){
        inc(j, 0, z){
            ans.pb(w[i]+c[j]);
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    inc(i, 0, k){
        cout << ans[i] << endl;
    }
    return 0;
}
