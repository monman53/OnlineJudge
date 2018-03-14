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

bool valid(double h, double i, double j) {
    return hypot(i-h/2, j-h/2) < h/2+1e-8;
}

int solve(int h, int k) {
    int cnt = 0;
    inc(i, 0, h/k){
        inc(j, 0, h/k){
            if(valid(h, i*k, j*k) &&
               valid(h, i*k+k, j*k) &&
               valid(h, i*k, j*k+k) &&
               valid(h, i*k+k, j*k+k)){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    int k;cin >> k;
    cout << solve(200, k) << " " << solve(300, k) << endl;
    return 0;
}
