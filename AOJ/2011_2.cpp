#include <iostream>
#include <vector>
using namespace std;

/*
DPでの解法がわからない
*/

int main(){
  while(1){
    int n;
    cin >> n;
    if(n == 0) break;

    vector<vector<bool>> data(n, vector<bool>(31, false));
    bool dp[31][n][n];
    for(int i=0;i<31;i++){
      for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
          dp[i][j][k] = false;
        }
      }
    }
    
    for(int i=0;i<n;i++){
      int f;
      cin >> f;
      for(int j=0;j<f;j++){
        int m;
        cin >> m;
        data[i][m] = true;
      }
      dp[0][i][i] = true;
    }
    bool end = false;
    for(int i=0;i<30;i++){
      for(int j=0;j<n;j++){
        int count = 0;
        for(int k=0;k<n;k++){
          if(dp[i][j][k]){
            for(int l=i+1;l<31;l++){
              if(data[j][l]){
                for(int m=0;m<n;m++){
                  if(data[m][l]){
                    dp[l][m][j];
                  }
                }
              }
            }
            count++;
          }
        }
        if(count == n){
          cout << i+1 << '\n';
          end = true;
          break;
        }
      }
      if(end)break;
    }
    if(!end){
      cout << -1 << '\n';
    }
  }
}
