#include <iostream>
using namespace std;

#define N 600

int main(){
  int q[N];
  for(int i=0;i<N;i++){
    q[i] = i*(i+1)*(i+2)/6;
  }
  int ans[1000000];
  int ansk[1000000];
  /*for(int i=0;i<1000000;i++){
    ans[i] = -1;
  }*/
  ans[0] = 0;
  ansk[0] = 0;
  int min, mink;
  for(int i=1;i<1000000;i++){
    min=99;
    mink=1111111;
    for(int j=N-1;j>=1;j--){
      if(q[j] <= i){
        if(q[j]%2 == 1){
          if(ansk[i - q[j]] + 1 < mink){
            mink = ansk[i - q[j]] + 1;
          }
        }
        if(ans[i - q[j]] + 1 <  min){
          min = ans[i - q[j]] + 1; 
        }
      }
    }
    ans[i] = min;
    ansk[i] = mink;
  }

  int n;

  while(1){
    cin >> n;
    if(n == 0) break;
    cout << ans[n] << ' ' << ansk[n] << '\n';
  }

  return 0;
}
