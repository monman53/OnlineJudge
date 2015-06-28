#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 1 << 30;

int main(){
  string s;

  while(1){
    cin >> s;
    if(s == "#") break;

    int n = (int)s.size();
    vector<vector<vector<vector<int> > > > dp(n+1, vector<vector<vector<int> > >(3, vector<vector<int> >(3, vector<int>(2, INF))));

    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(i%3 <= j%3){
          dp[0][i][j][0] = 0;
          dp[0][i][j][1] = 0;
        }else{
          dp[0][i][j][0] = 1;
          dp[0][i][j][1] = 1;
        }
      }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
          for(int l=0;l<2;l++){
            if(dp[i][j][k][l] == INF) continue;
            int next = (s[i]-'0'-1)%3;
            if(l==0){
              if(next <= k){
                dp[i+1][next][k][1-l] = min(dp[i+1][next][k][1-l], dp[i][j][k][l]);
              }else{
                dp[i+1][j][next][l] = min(dp[i+1][j][next][l], dp[i][j][k][l] + 1);
              }
            }else{
              if(next >= j){
                dp[i+1][j][next][1-l] = min(dp[i+1][j][next][1-l], dp[i][j][k][l]);
              }else{
                dp[i+1][next][k][l] = min(dp[i+1][next][k][l], dp[i][j][k][l] + 1);
              }
            }
          }
        }
      }
    }

    if(n == 1){
      cout << 0 << '\n';
    }else{
      int mmin = INF;
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          for(int k=0;k<2;k++){
            mmin = min(mmin, dp[n][i][j][k]);
          }
        }
      }
      cout << mmin << '\n';
    }
  }
  return 0;
}
