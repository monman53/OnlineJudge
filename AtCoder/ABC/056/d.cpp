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

int n, k;
int dp1[5005][5005];
int dp2[5005][5005];
int a[5005];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    inc(i, 0, n) cin >> a[i];
    dp1[0][0] = dp2[n][0] = 1;
    inc(i, 0, n){
        inc(j, 0, k){
            if(!dp1[i][j]) continue;

            dp1[i+1][j] = 1;
            if(j+a[i] < k){
                dp1[i+1][j+a[i]] = 1;
            }
        }
    }
    dec(i, 0, n){
        inc(j, 0, k){
            if(!dp2[i+1][j]) continue;

            dp2[i][j] = 1;
            if(j+a[i] < k){
                dp2[i][j+a[i]] = 1;
            }
        }
    }

    int cnt = 0;
    inc(i, 0, n){
        int rui[5005];
        mset(rui, 0);
        inc(j, 0, k){
            rui[j+1] = rui[j]+dp1[i][j];
        }

        bool f = false;
        inc(j, 0, k){
            if(!dp2[i+1][j]) continue;

            if(rui[k-j]-rui[max(0, k-a[i]-j)] > 0){
                f = true;
            }
        }
        if(!f) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
