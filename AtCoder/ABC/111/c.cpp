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

int solve(vector<int> v, int mid){
    int res = 0;
    for(auto vv : v){
        if(abs(mid-vv)){
            res++;
        }
    }
    return res;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a, b;
    inc(i, 0, n){
        int v;cin >> v;
        if(i%2){
            a.pb(v);
        }else{
            b.pb(v);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mida = a[n/2/2];
    int midb = b[n/2/2];
    if(mida == midb){
        cout << min({solve(a, mida) + solve(b, midb-1),
                     solve(a, mida-1) + solve(b, midb),
                     solve(a, mida) + solve(b, midb+1),
                     solve(a, mida+1) + solve(b, midb),
                     }) << endl;
    }else{
        cout << solve(a, mida) + solve(b, midb) << endl;
    }
    return 0;
}
