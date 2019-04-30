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
    LL a, b, q;cin >> a >> b >> q;
    vector<LL> s(a), t(b), x(q);
    inc(i, 0, a) cin >> s[i];
    inc(i, 0, b) cin >> t[i];
    inc(i, 0, q) cin >> x[i];
    inc(i, 0, q){
        int ls = lower_bound(s.begin(), s.end(), x[i]) - s.begin()-1;
        int rs = upper_bound(s.begin(), s.end(), x[i]) - s.begin();
        int lt = lower_bound(t.begin(), t.end(), x[i]) - t.begin()-1;
        int rt = upper_bound(t.begin(), t.end(), x[i]) - t.begin();
        vector<LL> v;
        if(ls != -1 && lt != -1) v.pb(x[i] - min(s[ls], t[lt]));
        if(ls != -1 && rt !=  b) v.pb(min(x[i] - s[ls], t[rt] - x[i]) + (t[rt] - s[ls]));
        if(rs !=  a && lt != -1) v.pb(min(x[i] - t[lt], s[rs] - x[i]) + (s[rs] - t[lt]));
        if(rs !=  a && rt !=  b) v.pb(max(s[rs], t[rt]) - x[i]);
        cout << *min_element(v.begin(), v.end()) << endl;
    }
    return 0;
}
