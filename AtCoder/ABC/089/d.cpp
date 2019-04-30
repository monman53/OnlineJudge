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

int sum[90005];
int ii[90005];
int jj[90005];

int main() {
    std::ios::sync_with_stdio(false);
    int h, w, d;cin >> h >> w >> d;
    inc(i, 0, h){
        inc(j, 0, w){
            int a;cin >> a;
            ii[a] = i;
            jj[a] = j;
        }
    }
    inc(k, 1, h*w+1){
        if(k+d <= h*w){
            int dist = abs(ii[k+d]-ii[k]) + abs(jj[k+d]-jj[k]);
            sum[k+d] = sum[k] + dist;
        }
    }

    int q;cin >> q;
    inc(i, 0, q){
        int l, r;cin >> l >> r;
        cout << sum[r]-sum[l] << endl;
    }
    return 0;
}
