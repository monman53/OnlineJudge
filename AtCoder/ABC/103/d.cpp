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
    int n, m;cin >> n >> m;
    vector<pair<int, int>> v;
    inc(i, 0, m){
        int a, b;cin >> a >> b;
        //a--;
        v.pb({a, b});
    }
    sort(v.begin(), v.end());
    int ans = 1;
    int l = 0;
    int r = n;
    inc(i, 0, m){
        int a = v[i].fi;
        int b = v[i].se;
        if(l <= a && a < r){
            l = max(l, a);
            r = min(r, b);
        }else{
            ans++;
            l = a;
            r = b;
        }
    }
    cout << ans << endl;
    return 0;
}
