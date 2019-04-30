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
    LL n;LL d;cin >> n >> d;
    vector<LL> x(n);
    inc(i, 0, n) cin >> x[i];
    LL ans = 0;
    inc(j, 1, n-1){
        LL ok = j;
        LL ng = -1;
        while(ok-ng>1){
            LL c = (ok+ng)/2;
            if(x[j]-x[c] <= d){
                ok = c;
            }else{
                ng = c;
            }
        }

        LL l = ok;

        ok = j;
        ng = n;
        while(ng-ok>1){
            LL c = (ok+ng)/2LL;
            if(x[c]-x[j] <= d){
                ok = c;
            }else{
                ng = c;
            }
        }

        LL r = ok;

        //cout << j << ":" << (j-l)*(r-j) << endl;
        ans += (j-l)*(r-j);
    }

    //cout << ans << endl;

    inc(i, 0, n-2){
        LL ok = i;
        LL ng = n;
        while(ng-ok>1){
            LL c = (ok+ng)/2LL;
            if(x[c]-x[i] <= d){
                ok = c;
            }else{
                ng = c;
            }
        }

        //cout << i << ":" << ok << endl;

        LL hoge = ok-i;

        if(hoge >= 2){
            ans -= hoge*(hoge-1LL)/2LL;
        }
    }


    printf("%lld\n", ans);
    return 0;
}
