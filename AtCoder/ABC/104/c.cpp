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

LL dp[2][200005];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    LL d, g;cin >> d >> g;g /= 100;
    vector<LL> p(d), c(d);
    inc(i, 0, d){
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    inc(i, 0, 2){
        inc(j, 0, 200005){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    inc(i, 0, d){
        inc(k, 0, 200005){
            dp[(i+1)%2][k] = dp[i%2][k];
        }
        inc(j, 0, p[i]-1){
            inc(k, 0, 200005){
                if(dp[i%2][k] != INF){
                    if(k+(i+1)*(j+1) < 200005){
                        dp[(i+1)%2][k+(i+1)*(j+1)] = min(dp[(i+1)%2][k+(i+1)*(j+1)], dp[i%2][k]+(j+1));
                    }
                }
            }
        }
        inc(k, 0, 200005){
            if(k+(i+1)*p[i]+c[i] < 200005){
                dp[(i+1)%2][k+(i+1)*p[i]+c[i]] = min(dp[(i+1)%2][k+(i+1)*p[i]+c[i]], dp[i%2][k]+p[i]);
            }
        }
    }

    LL ans = INF;
    dec(i, g, 200005){
        ans = min(ans, dp[d%2][i]);
    }

    cout << ans << endl;
    return 0;
}
