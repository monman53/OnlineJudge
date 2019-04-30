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

int d[30][30];
int c[500][500];
int v[3][30];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    int C;cin >> C;
    inc(i, 0, C){
        inc(j, 0, C){
            cin >> d[i][j];
        }
    }
    inc(i, 0, n){
        inc(j, 0, n){
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    inc(x, 0, C){
        inc(i, 0, n){
            inc(j, 0, n){
                v[(i+j)%3][x] += d[c[i][j]][x];
            }
        }
    }
    int ans = INT_MAX;
    inc(x, 0, C){
        inc(y, 0, C){
            inc(z, 0, C){
                if(x == y || y == z || z == x) continue;
                ans = min(ans, v[0][x]+v[1][y]+v[2][z]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
