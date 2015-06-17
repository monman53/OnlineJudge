#include <iostream>
#include <cmath>
using namespace std;

int ans(int n, int from, int count, int sum){
  int ret=0;
  for(int i=from;sum+i*i<=n;i++){
    if(sum + i*i == n){
      ret++;
    }
    if(count != 4){
      ret += ans(n, i, count+1, sum+i*i);
    }
  }
  return ret;
}

int main(){
  int n;
  while(1){
    cin >> n;
    if(n == 0) break;
    cout << ans(n, 1, 1, 0) << '\n';
  }
  return 0;
}
