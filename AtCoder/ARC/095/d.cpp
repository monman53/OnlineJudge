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
    sort(a.begin(), a.end());
    int ans1 = a[n-1];
    int ans2 = a[0];
    int mmin = 1000000005;
    inc(i, 0, n){
        int aa = a[i];
        if(ans1%2 == 0){
            int d = abs(ans1/2 - aa);
            if(d < mmin){
                ans2 = aa;
                mmin = d;
            }
        }else{
            int d = min(abs(ans1/2 - aa), abs(ans1/2 - aa + 1));
            if(d < mmin){
                ans2 = aa;
                mmin = d;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
