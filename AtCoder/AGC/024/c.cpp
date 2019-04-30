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
    int n;cin >> n;
    vector<int> a(n);
    inc(i, 0, n) cin >> a[i];
    inc(i, 0, n){
        if(i-a[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    dec(i, 1, n){
        if(a[i]-a[i-1] > 1){
            cout << -1 << endl;
            return 0;
        }
    }
    LL ans = a[n-1];
    dec(i, 1, n){
        if(a[i]-a[i-1] != 1){
            ans += a[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}
