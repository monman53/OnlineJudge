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

LL sum[100005][4];

LL mpow(LL a, LL b) {
    if(b == 0) return 1;
    LL aa = mpow(a, b/2);
    return aa*aa%MOD*(b%2 == 1 ? a : 1)%MOD;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string s;cin >> s;
    int n = s.size();
    inc(i, 0, n){
        inc(j, 0, 4){
            sum[i+1][j] = sum[i][j];
        }
        if(s[i] == 'A') sum[i+1][0]++;
        if(s[i] == 'B') sum[i+1][1]++;
        if(s[i] == 'C') sum[i+1][2]++;
        if(s[i] == '?') sum[i+1][3]++;
    }

    LL ans = 0;

    inc(i, 1, n-1){
        if(s[i] == 'B' || s[i] == '?'){
            LL la = sum[i][0];
            LL lq = sum[i][3];
            LL rc = sum[n][2]-sum[i+1][2];
            LL rq = sum[n][3]-sum[i+1][3];

            LL d = la*rc;
            LL ld = 0, rd = 0;

            if(la > 0){
                ld = mpow(3, lq);
            }else{
                ld = mpow(2, lq)+MOD-1;
            }

            if(rc > 0){
                rd = mpow(3, rq);
            }else{
                ld = mpow(2, rq)+MOD-1;
            }

            d += ld*rd;

            cout << d << endl;
            MODA(ans, d);
        }
    }

    cout << ans << endl;
    return 0;
}
