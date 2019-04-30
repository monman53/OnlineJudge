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

const double pi = acos(-1);

double area(double dt) {
    return sin(dt)+sqrt(2.0)*cos(dt);
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    inc(i, 0, n){
        double a;cin >> a;

        if(a < sqrt(2.0)){
            double ans = acos(a/sqrt(2.0)) + pi/4.0;

            printf("Case #%d:\n", i+1);
            printf("%.9lf %.9lf %.9lf\n", 0.5*cos(ans), 0.5*sin(ans), 0.0);
            printf("%.9lf %.9lf %.9lf\n", 0.5*cos(ans+pi/2.0), 0.5*sin(ans+pi/2.0), 0.0);
            printf("%.9lf %.9lf %.9lf\n", 0.0, 0.0, 0.5);
        }else{
            double l = 0;
            double r = 2.0*(pi*0-atan(sqrt(2.0)-sqrt(3.0)));

            inc(i, 0, 1000){
                double c = (l+r)/2.0;
                if(area(c) < a){
                    l = c;
                }else{
                    r = c;
                }
            }

            double ans = l;
            //printf("%lf\n", l);
            printf("Case #%d:\n", i+1);
            double R = sqrt(2.0)/4.0;
            printf("%.9lf %.9lf %.9lf\n", R, R*cos(ans), -R*sin(ans));
            printf("%.9lf %.9lf %.9lf\n", -R, R*cos(ans), -R*sin(ans));
            printf("%.9lf %.9lf %.9lf\n", 0.0, 0.5*sin(ans), 0.5*cos(ans));
        }
    }

    return 0;
}
