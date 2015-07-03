#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int INF = 1 << 30;

int main(){
  while(1){
    int w, h;
    cin >> w >> h;
    if(w == 0) break;

    vector<vector<char>> map(h, vector<char>(w));
    //vector<vector<vector<int>>> dp[h][w][2]; 
    int dp[h][w][2];
    int di[2][9] = {{-2, -1, 0, 1, 2, -1, 0, 1, 0},
                    {-2, -1, 0, 1, 2, -1, 0, 1, 0}};
    int dj[2][9] = {{1, 1, 1, 1, 1, 2, 2, 2, 3},
                    {-1, -1, -1, -1, -1, -2, -2, -2, -3}};
    
    // input map
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin >> map[i][j];
        dp[i][j][0] = INF;
        dp[i][j][1] = INF;
        if(map[i][j] == 'S'){
          dp[i][j][0] = 0;
          dp[i][j][1] = 0;
        }
      }
    }

    // dp
    bool flag = true;
    while(flag){
      flag = false;
    for(int i=h-1;i>=0;i--){
      for(int j=0;j<w;j++){
        for(int k=0;k<2;k++){
          if(dp[i][j][k] != INF){
            for(int l=0;l<9;l++){
              int ni = i + di[k][l];
              int nj = j + dj[k][l];
              if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                if(map[ni][nj] >= '1' && map[ni][nj] <= '9'){
                  if(dp[ni][nj][1-k] > dp[i][j][k] + (map[ni][nj]-'0')){
                    dp[ni][nj][1-k] = dp[i][j][k] + (map[ni][nj]-'0');
                    flag = true;
                  }
                  //dp[ni][nj][1-k] = min(dp[ni][nj][1-k],
                  //  dp[i][j][k] + (map[ni][nj]-'0'));
                }else if(map[ni][nj] == 'T'){
                  if(dp[ni][nj][1-k] > dp[i][j][k]){
                    dp[ni][nj][1-k] = dp[i][j][k];
                    flag = true;
                  }
                  //dp[ni][nj][1-k] = min(dp[ni][nj][1-k],
                  //  dp[i][j][k]);
                }
              }
            }
          }
        }
      }
    }
    }


    int ans = INF;
    for(int i=0;i<w;i++){
      for(int j=0;j<2;j++){
        if(map[0][i] == 'T'){
          ans = min(ans, dp[0][i][j]);
        }
      }
    }

    if(ans == INF){
      cout << -1 << '\n';
    }else{
      cout << ans << '\n';
    }
    
  }
}
