// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define EPS         (1e-9)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;double r;cin >> n >> r;
    vector<double> x(n);
    vector<double> y(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++){
        double ymax = r;
        for(int j=0;j<i;j++){
            double dx = x[i]-x[j];
            if(dx > 2*r+EPS) continue;
            double dy = sqrt(4*r*r-dx*dx);
            ymax = max(ymax, y[j]+dy);
        }
        y[i] = ymax;
    }
    for(int i=0;i<n;i++){
        printf("%.10f", y[i]);
        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
