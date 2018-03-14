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

double p;

double f(double x) {
    return x+p/pow(2, x/1.5);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> p;
    double l = 0;
    double r = p;
    while(r-l>1e-9){
        double ml = (l*2+r)/3;
        double mr = (l+r*2)/3;
        if(f(ml) < f(mr)){
            r = mr;
        }else{
            l = ml;
        }
    }
    printf("%.10lf", f(l));
    return 0;
}
