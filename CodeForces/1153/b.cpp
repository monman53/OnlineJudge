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

int n, m, h;
int ans[100][100];
int a[100], b[100];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n >> m >> h;
    inc(i, 0, m) cin >> a[i];
    inc(i, 0, n) cin >> b[i];
    inc(i, 0, n){
        inc(j, 0, m){
            cin >> ans[i][j];
        }
    }

    inc(i, 0, n){
        inc(j, 0, m){
            if(ans[i][j] == 1){
                if(b[i] <= a[j]){
                    ans[i][j] = b[i];
                }
                if(a[j] <= b[i]){
                    ans[i][j] = a[j];
                }
            }
        }
    }

    inc(i, 0, n){
        inc(j, 0, m){
            cout << ans[i][j];
            if(j < m-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
