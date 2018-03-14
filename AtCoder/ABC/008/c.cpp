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

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> c(n);
    inc(i, 0, n) cin >> c[i];
    double ans = 0;
    inc(i, 0, n){
        int cnt = 0;
        inc(j, 0, n){
            if(i == j) continue;
            if(c[i]%c[j] == 0) cnt++;
        }
        if(cnt%2 == 0){
            ans += double(cnt+2)/(2*cnt+2);
        }else{
            ans += 1.0/2;
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}
