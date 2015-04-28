#include <iostream>
using namespace std;

long long int dp[100][21];

int main(){
    int n;
    for(int i=0;i<100;i++){
        for(int j=0;j<21;j++){
            dp[i][j] = 0;
        }
    }
    cin >> n;
    int b;
    cin >> b;
    dp[0][b] = 1;
    for(int i=1;i<n-1;i++){
        int a;
        cin >> a;
        for(int j=0;j<=20;j++){
            if(j+a >= 0 && j+a <= 20) dp[i][j+a] += dp[i-1][j];
            if(j-a >= 0 && j-a <= 20) dp[i][j-a] += dp[i-1][j];
        }
    }
    cin >> b;
    cout << dp[n-2][b] << '\n';
    return 0;
}
