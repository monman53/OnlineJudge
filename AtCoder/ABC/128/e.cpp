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
    LL n, q;cin >> n >> q;
    vector<LL> s(n), t(n), x(n);
    vector<pair<LL, pair<LL, LL>>> v;
    inc(i, 0, n){
        cin >> s[i] >> t[i] >> x[i];
        s[i]*=2;
        t[i]*=2;
        v.pb({x[i], {s[i]-1, t[i]-1}});
    }
    sort(v.begin(), v.end());
    vector<pair<LL, int>> d;
    inc(i, 0, q){
        LL dd;cin >> dd;
        d.pb({dd*2, i});
    }
    sort(d.begin(), d.end());
    vector<LL> ans(q, -1);

    inc(i, 0, n){
        int l = -1;
        int r = d.size();
        s[i] = v[i].se.fi;
        t[i] = v[i].se.se;
        x[i] = v[i].fi;
        while(r-l>1){
            int m = (r+l)/2;
            if(d[m].fi < s[i]-x[i]*2){
                l = m;
            }else{
                r = m;
            }
        }
//        cout << s[i] << " " << t[i] << endl;
//        for(auto dd : d){
//            cout << dd.fi << ":" << dd.se << ", ";
//        }
//        cout << endl;
        while(r < d.size()){
            if(d[r].fi > t[i]-x[i]*2) break;
            ans[d[r].se] = x[i];
            d.erase(d.begin()+r);
        }
    }
    inc(i, 0, q){
        cout << ans[i] << endl;
    }
    return 0;
}
