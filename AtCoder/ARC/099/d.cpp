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
    LL k;cin >> k;
    vector<LL> ans;
    inc(i, 1, 10) ans.pb(i);
    inc(i, 1, 10) ans.pb(i*10+9);
    inc(i, 2, 15){
        LL d = 1;
        inc(k, 0, i){
            d *= 10LL;
        }
        inc(j, (i>10?i-2:i-1), (i>10?10*(i-1):10*i)){
            ans.pb(j*d+(d-1));
        }
    }

    //for(auto a : ans){
        //cout << a << endl;
    //}

    inc(i, 0, k){
        cout << ans[i] << endl;
    }
    return 0;
}
