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
    LL n, m;cin >> n >> m;
    vector<pair<LL, LL>> v;
    inc(i, 0, n){
        LL a, b;cin >> a >> b;
        v.pb({a, b});
    }
    sort(v.begin(), v.end());
    LL ans = 0;
    inc(i, 0, n){
        if(m >= v[i].se){
            ans += v[i].fi*v[i].se;
            m -= v[i].se;
        }else{
            ans += m*v[i].fi;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
