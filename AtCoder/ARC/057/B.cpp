#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <climits>
using namespace std;
typedef unsigned long long ull;
#define MAX 9999999

ull dp[2005][2005];
int main(){
    int n, K;
    cin >> n >> K;
    int a[2005];
    ull sum[2005];
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    a[0] = 0;
    sum[0] = 1;
    for(int i=0;i<2005;i++) for(int j=0;j<2005;j++) dp[i][j] = MAX;
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=n;k++){
            if(dp[i-1][k] == MAX) continue;
            for(int j=0;j<=a[i];j++){
                if(double(k)/double(sum[i-1]) < double(k+j)/double(sum[i])){
                    cout << "kita" << endl;
                    dp[i][k+j] = min(dp[i][k+j], dp[i][k] + j);
                }
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=K;j++){
            if(dp[i][j] == K){
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
