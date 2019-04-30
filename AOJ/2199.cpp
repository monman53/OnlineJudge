#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 1 << 30;

int main(){
  int n, m;
  while(1){
    cin >> n >> m;
    if(n == 0 && m == 0) break;

    vector<vector<int> > dp(n+1, vector<int>(256, INF));
    dp[0][128] = 0;
    vector<int> codebook(m);
    vector<int> data(n);

    for(int i=0;i<m;i++) cin >> codebook[i];
    for(int i=0;i<n;i++) cin >> data[i];

    for(int i=0;i<n;i++){
      for(int j=0;j<256;j++){
        if(dp[i][j] == INF) continue;
        for(int k=0;k<m;k++){
          int next = j+codebook[k];
          if(next < 0) next = 0;
          if(next > 255) next = 255;

          dp[i+1][next] = min(dp[i+1][next], dp[i][j]+(next-data[i])*(next-data[i]));
        }
      }
    }
    int mmin=INF;
    for(int i=0;i<256;i++){
      mmin = min(mmin, dp[n][i]);
    }
    cout << mmin << '\n';
  }
}
