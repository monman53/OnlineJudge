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

LL n, m, k;
vector<pair<LL, int>> v;
vector<int> vv;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    inc(i, 0, n){
        LL a;cin >> a;
        v.pb({a, i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    LL sum = 0;
    inc(i, 0, m*k){
        sum += v[i].fi;
        vv.pb(v[i].se);
        //cout << v[i].fi << " " << v[i].se << endl;
    }

    sort(vv.begin(), vv.end());
    vector<int> ans;
    inc(i, 0, m*k){
        if(i%m==0){
            ans.pb(vv[i]);
        }
    }

    cout << sum << endl;
    inc(i, 1, k){
        cout << ans[i];
        if(i != k-1){
            cout << " ";
        }
    }
    cout << endl;


    return 0;
}
