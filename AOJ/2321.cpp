#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){
  while(1){
    int n;
    cin >> n;
    if(n == 0) break;

    vector<ll> dp(1<<16, 0);
    vector<int> time(n, 0);
    vector<ll> l(n);

    for(int i=0;i<n;i++){
      int m;
      cin >> m >> l[i];
      for(int j=0;j<m;j++){
        int s, e;
        cin >> s >> e;
        for(int k=s-6;k<e-6;k++){
          time[i] |= (1 << k);
        }
      }
//      cout << time[i] << endl;
    }

    ll ans = 0;

    for(int i=0;i<(1<<16);i++){
      ans = max(ans, dp[i]);
      for(int j=0;j<n;j++){
        if((i & time[j]) == 0){
          dp[i | time[j]] = max(dp[i | time[j]], dp[i] + l[j]);
        }
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
