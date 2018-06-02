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
    int a, b, c;cin >> a >> b >> c;
    int mx = max({a, b, c});
    int ans = 0;
    if(a < mx){
        int k = (mx-a)/2;
        ans += k;
        a += k*2;
    }
    if(b < mx){
        int k = (mx-b)/2;
        ans += k;
        b += k*2;
    }
    if(c < mx){
        int k = (mx-c)/2;
        ans += k;
        c += k*2;
    }
    int da = mx-a;
    int db = mx-b;
    int dc = mx-c;
    if(da == 0 && db == 0 && dc == 0) ans += 0;
    if(da == 0 && db == 0 && dc == 1) ans += 2;
    if(da == 0 && db == 1 && dc == 0) ans += 2;
    if(da == 1 && db == 0 && dc == 0) ans += 2;
    if(da == 0 && db == 1 && dc == 1) ans += 1;
    if(da == 1 && db == 0 && dc == 1) ans += 1;
    if(da == 1 && db == 1 && dc == 0) ans += 1;
    if(da == 1 && db == 1 && dc == 1) ans += 2;
    cout << ans << endl;
    return 0;
}
