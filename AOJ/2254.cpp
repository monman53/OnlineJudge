#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MAX = 1<<30;

int main(){
  int n;
  while(1){
    cin >> n;
    if(n == 0) return 0;

    int data[16][17];
    int nbit = 1 << n;
    vector<int> dp(nbit, MAX);

    for(int i=0;i<n;i++){
      for(int j=0;j<n+1;j++){
        cin >> data[i][j];
      }
    }
    dp[0] = 0;
    for(int i=0;i<nbit;i++){
      for(int j=0;j<n;j++){
        if(!(i&(1<<j))){
          int mmin = dp[i] + data[j][0];
          for(int k=0;k<n;k++){
            if(i&(1<<k)){
              mmin = min(mmin, dp[i] + data[j][k+1]);
            }
          }
          dp[i|(1<<j)] = min(mmin, dp[i|(1<<j)]);
        }
      }
    }
    cout << dp[nbit-1] << '\n';
  }
  return 0;
}
