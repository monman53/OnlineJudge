// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int cum[1005][1005][2];
int sum[1005][1005][2];

inline int f(int i, int j, int fi, int fj, int k) {
    return sum[i+1][j+1][k]-sum[i+1][fj][k]-sum[fi][j+1][k]+sum[fi][fj][k];
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    map<pair<pair<int, int>, int>, int> st;

    inc(i, 0, n){
        int x, y;char c;cin >> x >> y >> c;
        int m = x/k + y/k;
        int cc = (c == 'W');
        if(m%2 != 0) cc = 1-cc;
        st[{{x%k, y%k}, cc}]++;
    }

    for(auto kv : st){
        cum[kv.fi.fi.fi][kv.fi.fi.se][kv.fi.se] += kv.se;
    }

    inc(i, 1, k+1){
        inc(j, 1, k+1){
            inc(l, 0, 2){
                sum[i][j][l] = sum[i][j-1][l] + sum[i-1][j][l] - sum[i-1][j-1][l] + cum[i-1][j-1][l];
            }
        }
    }

    int ans = 0;
    inc(i, 0, k+1){
        inc(j, 0, k+1){
            inc(l, 0, 2){
                int m = f(k-1, k-1, i, j, l) + f(i-1, j-1, 0, 0, l)
                       +f(k-1, j-1, i, 0, 1-l)+f(i-1, k-1, 0, j, 1-l);
                ans = max(ans, m);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
