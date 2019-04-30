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
    int n;cin >> n;
    string s;cin >> s;
    int mx = 0;
    int cnt = 0;
    double ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '>'){
            ans += 1.0/(cnt+2);
            cnt++;
        }else{
            mx = max(mx, cnt);
            ans += 1.0;
            cnt=0;
        }
    }
    printf("%.9lf\n", ans-1.0+1.0/(mx+2));
    return 0;
}
