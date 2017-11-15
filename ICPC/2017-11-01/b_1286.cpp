#include <bits/stdc++.h>
using namespace std;

int sum[100000];
int n, m, k;

void solve(int i, int now) {
    if(i == n){
        sum[max(now-k, 1)]++;
        return;
    }
    for(int j=1;j<=m;j++){
        solve(i+1, now+j);
    }
}

int main() {
    while(true){
        cin >> n >> m >> k;
        if(n == 0) break;
        memset(sum, 0, sizeof(sum));
        solve(0, 0);
        double ans = 0;
        double sub = 1;
        for(int i=0;i<n;i++){
            sub *= m;
        }
        for(int i=0;i<=n*m;i++){
            ans += (double)sum[i]*i/sub;
        }
        printf("%.9lf\n", ans);
    }
    return 0;
}
