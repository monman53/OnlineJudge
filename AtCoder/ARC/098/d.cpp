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
    LL n;cin >> n;
    vector<LL> a(n);
    inc(i, 0, n) cin >> a[i];
    vector<LL> b(n, -1);

    dec(i, 0, n){
        if(a[i] == 0 && b[i] == -1){
            int j=i;
            for(;j>=0;j--){
                if(a[j] == 0){
                    b[j] = i;
                }else{
                    break;
                }
            }
        }
    }

    LL ans = 0;
    inc(i, 0, n){
        LL x = 0;
        LL s = 0;
        int j = i;
        while(j<n){
            if(a[j] == 0){
                j = b[j]+1;
                continue;
            }
            x ^= a[j];
            s += a[j];
            if(x != s){
                break;
            }
            j++;
        }
        ans += j-i;
    }
    cout << ans << endl;
    return 0;
}
