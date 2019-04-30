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
    LL n;cin >> n;
    vector<LL> a(n), b(n);
    inc(i, 0, n) cin >> a[i];
    inc(i, 0, n) cin >> b[i];

    LL sum = 0;

    inc(i, 0, n){
        if(a[i] > b[i]){
            sum += a[i] - b[i];
        }
    }

    inc(i, 0, n){
        if(b[i] > a[i]){
            sum -= (b[i]-a[i])/2;
        }
    }

    if(sum > 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}
