#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  double t, d;
  double ta, tb, da, db;
  cin >> t >> d;
  cin >> ta >> tb >> da >> db;

  double ans = fabs(ta - t);

  for(int i=0;da*i<=d;i++){
    for(int j=0;da*i+db*j<=d;j++){
      if(i == 0 && j == 0) continue;
      ans = min(ans, abs(t - (ta*da*i+tb*db*j)/(da*i+db*j)));
    }
  }
  
  cout << ans << '\n';

  return 0;
}
