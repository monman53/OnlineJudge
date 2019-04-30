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
    vector<LL> x(m);
    inc(i, 0, m) cin >> x[i];
    if(m == 1){
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    vector<LL> d;
    inc(i, 1, m) d.pb(x[i]-x[i-1]);
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    if(n == 1){
        LL sum = 0;
        inc(i, 0, m-1){
            sum += d[i];
        }
        cout << sum << endl;
    }else{
        LL ans = 0;
        int nn = n-2;
        inc(i, 1, m-1){
            if(nn == 0){
                ans += d[i];
            }else{
                nn--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
