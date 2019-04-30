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
    int t;cin >> t;
    inc(i, 0, t){
        int n;cin >> n;
        vector<int> a(n), b(n);
        inc(j, 0, n) cin >> a[j];
        inc(j, 0, n) cin >> b[j];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int as = 0;
        int bs = 0;
        inc(j, 0, n-1) as += a[j];
        inc(j, 0, n-1) bs += b[j];
        //cout << as << " " << bs << endl;
        string ans = "Draw";
        if(as < bs) ans = "Alice";
        if(bs < as) ans = "Bob";
        cout << ans << endl;
    }
    return 0;
}
