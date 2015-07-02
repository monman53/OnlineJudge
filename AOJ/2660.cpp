#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

ll INF = 1 << 30;

ll time(ll x, ll y){
  ll res = 0;
  int c=0;
  for(ll i=1;x/i!=0||y/i!=0;i*=10){
    res += ((x/i)%10)*((y/i)%10) + c;
    if((x/i)%10+(y/i)%10+c >= 10){
      c = 1;
    }else{
      c = 0;
    }
  }
  res += c;
  return res;
}

ll a[300];
ll dp[300][300];
ll sum[301];

ll ans(int from, int to){
  ll res = INF;
  if(dp[from][to] != -1){
    return dp[from][to];
  }
  if(from == to){
    return 0;
  }
  for(int i=from;i<to;i++){
    res = min(res, ans(from, i) + ans(i+1, to) + time(sum[i+1]-sum[from], sum[to+1]-sum[i+1]));
  }
  return dp[from][to] = res;
}

int main(){
  int n;
  cin >> n;
  sum[0] = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
    for(int j=0;j<n;j++){
      dp[i][j] = -1;
    }
  }
  cout << ans(0, n-1) << '\n';
  return 0;
}
