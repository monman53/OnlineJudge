// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(r);i--)
#define se          second
#define fi          first

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    int a[300][300];
    int b[300][300];
    inc(i, 0, n){
        inc(j, 0, n){
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    inc(k, 0, n){
        inc(i, 0, n){
            inc(j, 0, n){
                b[i][j] = min(b[i][j], b[i][k]+b[k][j]);
            }
        }
    }
    inc(i, 0, n){
        inc(j, 0, n){
            if(b[i][j] < a[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    LL ans = 0;
    inc(i, 0, n){
        inc(j, i+1, n){
            bool f = false;
            inc(k, 0, n){
                if(k == i || k == j) continue;
                if(b[i][j] == b[i][k]+b[k][j]) f = true;
            }
            if(!f) ans += b[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}
