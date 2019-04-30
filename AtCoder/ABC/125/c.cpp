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

int gcd(int x, int y) {
    return y ? gcd(y, x%y) : x;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    inc(i, 0, n) cin >> a[i];
    vector<int> l(n), r(n);
    l[0] = a[0];
    r[n-1] = a[n-1];
    inc(i, 1, n){
        l[i] = gcd(l[i-1], a[i]);
    }
    dec(i, 0, n-1){
        r[i] = gcd(r[i+1], a[i]);
    }
    int ans = max(r[1], l[n-2]);
    inc(i, 1, n-1){
        ans = max(ans, gcd(l[i-1], r[i+1]));
    }

    cout << ans << endl;

    return 0;
}
