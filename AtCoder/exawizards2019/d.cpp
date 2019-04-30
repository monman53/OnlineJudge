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

int n;
int s[200];
LL fact[300];
int mmin = 100005;
int used[200];

LL ans = 0;

void dfs(int x, int y, int cnt) {
    if(y == mmin){
        MODA(ans, MODP(x, fact[n-cnt]));
    }else{
        inc(i, 0, n){
            if(used[i] == 0){
                used[i] = 1;
                dfs(x%s[i], s[i], cnt+1);
                used[i] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);

    cin >> n;
    int x;cin >> x;
    inc(i, 0, n){
        cin >> s[i];
        mmin = min(mmin, s[i]);
    }

    sort(s, s+n);

    fact[0] = 1;
    inc(i, 1, 300){
        fact[i] = fact[i-1]*i;
    }

    inc(i, 0, n){
        used[i] = 1;
        dfs(x%s[i], s[i], 1);
        used[i] = 0;
    }

    cout << ans << endl;

    return 0;
}
