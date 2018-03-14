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
    LL n, k;cin >> n >> k;
    LL ans = 0LL;
    if(k == 0){
        printf("%lld\n", n*n);
        return 0;
    }
    inc(i, k+1, n+1){
        LL j = i-k;
        LL m = (n+i-1)/i;
        //cout << j << " " << m << " " << m*j << " " << min(j, m*i-n-1) << endl;
        ans += m*j;
        //ans += (m*i-n);
        if(n%i == 0) continue;
        ans -= min(j, m*i-n-1);
        //ans -= ((n+i-1)/i*i-n)-1;
        
    }
    printf("%lld\n", ans);
    return 0;
}
