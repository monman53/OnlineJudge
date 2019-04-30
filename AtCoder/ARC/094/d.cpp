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
    int q;cin >> q;
    inc(i, 0, q){
        LL a, b;cin >> a >> b;
        LL c = a*b;

        LL ng = min(a, b)-1;
        LL ok = max(a, b)+1;
        while(ok-ng>1){
            LL m = (ng+ok)/2LL;
            if(ng*ng == c){
                break;
            }
            if(ok*ok == c){
                ng = ok;
                break;
            }
            if(m*m == c){
                ng = m;
                break;
            }else if(m*m < c){
                ng = m;
            }else{
                ok = m;
            }
        }
        LL d = ng;

        LL ans = (d-1)*2;
        if(d*(d+1) < c){
            ans++;
        }else if(d*d == c && a != d && b != d){
            ans--;
        }
        //if(a > d+(d-1)){
            //ans--;
        //}
        //if(b > d+(d-1)){
            //ans--;
        //}
        printf("%lld\n", ans);
        //cout << d << "#" << ans << endl;
    }
    return 0;
}
