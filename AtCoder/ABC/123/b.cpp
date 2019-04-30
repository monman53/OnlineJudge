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
    int a[5];
    inc(i, 0, 5) cin >> a[i];
    int v[5] = {0, 1, 2, 3, 4};
    int mmin = 100000000;
    do{
        int ans = 0;
        inc(i, 0, 4){
            ans += (a[v[i]]+10-1)/10*10;
        }
        ans += a[v[4]];
        mmin = min(ans, mmin);
    }while(next_permutation(v, v+5));
    cout << mmin << endl;
    return 0;
}
