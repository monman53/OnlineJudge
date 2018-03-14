// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    vector<LL> x(n), y(m);
    inc(i, 0, n) cin >> x[i];
    inc(i, 0, m) cin >> y[i];
    LL X = 0;
    inc(i, 0, n){
        X += x[i]*i-x[i]*(n-i-1);
        X %= MOD;
    }
    LL Y = 0;
    inc(i, 0, m){
        Y += y[i]*i-y[i]*(m-i-1);
        Y %= MOD;
    }
    //cout << X << " " << Y << endl;
    cout << X*Y%MOD << endl;
    return 0;
}
