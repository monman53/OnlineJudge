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

int n;
double x[1000], y[1000], c[1000];

bool valid(int i, int j, double t) {
    return max(abs(x[i]-x[j]), abs(y[i]-y[j])) < t/c[i]+t/c[j];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    inc(i, 0, n){
        cin >> x[i] >> y[i] >> c[i];
    }
    double ok = 1e10;
    double ng = 0;
    while(ok-ng>1e-5){
        double m = (ok+ng)/2;
        bool f = true;
        inc(i, 0, n){
            inc(j, i+1, n){
                f &= valid(i, j, m);
            }
        }
        if(f){
            ok = m;
        }else{
            ng = m;
        }
    }
    printf("%.8lf\n", ok);
    return 0;
}
