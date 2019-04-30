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
    int n, k, q;cin >> n >> k >> q;
    vector<int> a(n), b;
    inc(i, 0, n){
        cin >> a[i];
        b.pb(a[i]);
    }
    a.pb(0);
    b.pb(0);
    sort(b.begin(), b.end());

    int ans = INT_MAX;

    inc(i, 0, n+1){
        vector<int> u, v;
        inc(j, 0, n+1){
            if(a[j] <= b[i]){
                int m = u.size();
                if(m < k){
                    u.clear();
                    continue;
                }
                sort(u.begin(), u.end());
                inc(l, 0, m-k+1){
                    v.pb(u[l]);
                }
                u.clear();
            }else{
                u.pb(a[j]);
            }
        }

        int m = v.size();
        sort(v.begin(), v.end());
        if(m < q) continue;
        ans = min(ans, v[q-1]-v[0]);
    }

    cout << ans << endl;

    return 0;
}
