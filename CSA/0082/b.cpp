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
    LL a, b, c, d, x, y, z, w;
    LL v;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> z >> w;
    cin >> v;

    //LL ans0 = a*x + b*y + c*z + d*w;
    //LL ans1 = a*v + min(b-a, 0LL)*y + max(c-a, 0LL)*z + max(d-a, 0LL)*w;
    //LL ans2 = b*v + min(a-b, 0LL)*x + max(c-b, 0LL)*z + max(d-b, 0LL)*w;
    //LL ans3 = c*v + min(a-c, 0LL)*x + max(b-c, 0LL)*y + max(d-c, 0LL)*w;
    //LL ans4 = d*v + min(a-d, 0LL)*x + max(b-d, 0LL)*y + max(c-d, 0LL)*z;

    //cout << ans0 << " " << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;

    cout << min({
        a*x + b*y + c*z + d*w,
        a*v + max(b-a, 0LL)*y + max(c-a, 0LL)*z + max(d-a, 0LL)*w,
        b*v + max(a-b, 0LL)*x + max(c-b, 0LL)*z + max(d-b, 0LL)*w,
        c*v + max(a-c, 0LL)*x + max(b-c, 0LL)*y + max(d-c, 0LL)*w,
        d*v + max(a-d, 0LL)*x + max(b-d, 0LL)*y + max(c-d, 0LL)*z,
    }) << endl;
    return 0;
}
