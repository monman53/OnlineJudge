#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    int c[100000][3];
    int dp[100000][3];

    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin >> c[i][j];

    for(int i=0;i<3;i++)
        dp[0][i] = c[0][i];

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = 0;
            for(int k=0;k<3;k++){
                if(j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + c[i][j]);
            }
        }
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}
