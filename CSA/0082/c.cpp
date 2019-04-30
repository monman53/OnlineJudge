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
    LL n, s;cin >> n >> s;
    vector<LL> v(n);
    LL sum = 0;
    deque<pair<LL, int>> dq;
    inc(i, 0, n) cin >> v[i];
    inc(i, 0, n) sum += v[i];
    inc(i, 0, n) dq.pb({v[(i+s-1)%n], (i+s-1)%n});
    LL ans = 0;
    while((int)dq.size() > 1){
        auto f = dq.front();
        auto b = dq.back();
        dq.pop_front();
        dq.pop_back();
        if(f < b){
            ans += f.fi;
            dq.push_back({b.fi+f.fi, b.se});
        }else{
            ans += b.fi;
            dq.push_front({b.fi+f.fi, f.se});
        }
    }
    ans += min(dq.front().fi, sum-dq.front().fi);

    cout << ans << endl;
    return 0;
}
