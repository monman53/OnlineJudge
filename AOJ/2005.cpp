#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int INF = 1 << 20;

int main(){
  int n, m, s, g1, g2;
  while(1){
    cin >> n >> m >> s >> g1 >> g2;
    if(n == 0) break;
    int dp[n][n];
    // init
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dp[i][j] = INF;
        if(i == j){
          dp[i][j] = 0;
        }
      }
    }
    // input
    int b1, b2, c;
    for(int i=0;i<m;i++){
      cin >> b1 >> b2 >> c;
      dp[b1-1][b2-1] = c;
    }
    // WF
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    // output
    int ans = INF;
    for(int i=0;i<n;i++){
      ans = min(ans, dp[s-1][i] + dp[i][g1-1] + dp[i][g2-1]);
    }
    cout << ans << '\n';
  }
  return 0;
}
