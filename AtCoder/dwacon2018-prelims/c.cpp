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

//LL dp[100][1005];
vector<LL> vv;
int nn;

LL f(int i, int l, int m) {
    cout << i << " " << l << endl;
    if(i == nn-1 && l <= m){
        return 1;
    }else{
        return 0;
    }
    LL res = 0;
    if(vv[i] == vv[i+1]){
        for(int k=0;k<=min(m, l);k++){
            if(k<=l/2){
                res += f(i+1, k, k);
            }else{
                res += f(i+1, k, l-k);
            }
        }
    }else{
        for(int k=0;k<=min(m, l);k++){
            res += f(i+1, k, k);
        }
    }
    return res;
}

LL solve(vector<LL> v, LL sum) {
    reverse(v.begin(), v.end());
    nn = v.size();
    if(nn == 1) return 1;
    vv = v;
    return f(0, sum, sum);
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    vector<LL> a(n), b(m);
    inc(i, 0, n) cin >> a[i];
    inc(i, 0, m) cin >> b[i];
    LL sa = 0;
    LL sb = 0;
    inc(i, 0, n) sa += a[i];
    inc(i, 0, m) sb += b[i];

    cout << solve(a, sb)*solve(b, sa)%MOD << endl;
    return 0;
}
