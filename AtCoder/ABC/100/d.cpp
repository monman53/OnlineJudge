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
    vector<LL> v(n);
    inc(i, 0, n){
        LL x, y, z;cin >> x >> y >> z;
        v[i] = x+y+z;
    }

    sort(v.begin(), v.end());
    LL ans1 = 0;
    inc(i, 0, m) ans1 += v[i];
    LL ans2 = 0;
    inc(i, 0, m) ans2 += v[n-i-1];

    cout << max(abs(ans1), abs(ans2)) << endl;
    return 0;
}
