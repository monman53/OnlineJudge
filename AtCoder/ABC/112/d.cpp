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

int n, m;
int ans = 1;

void dfs(int a, int b) {
    if(b == 1){
        //cout << a << endl;
        if(m/a >= n){
            ans = max(ans, a);
        }
        return;
    }

    for(int i=2;i*i<=b;i++){
        if(b%i == 0){
            int cnt = 0;
            while(b%i==0){
                b /= i;
                cnt++;
            }
            int na = a;
            inc(j, 0, cnt+1){
                dfs(na, b);
                na *= i;
            }
            return;
        }
    }
    dfs(a, 1);
    dfs(a*b, 1);
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n >> m;
    dfs(1, m);
    cout << ans << endl;
    return 0;
}
