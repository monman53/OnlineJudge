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

double a, b, c;
double f(double t) {
    return a*t+b*sin(c*t*M_PI);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    double d = 0;
    double u = 200;
    //while(fabs(100-f(d))>1e-7){
    inc(i, 0, 100){
        double m = (u+d)/2;
        if(f(m) > 100){
            u = m;
        }else{
            d = m;
        }
    }
    printf("%.12lf\n", d);
    return 0;
}
