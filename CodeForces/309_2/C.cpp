#include <iostream>
using namespace std;

int main(){
  int k;

  cin >> k;

  int product[1001];
  int balls[1001];
  int sum=0;

  for(int i=1;i<=k;i++){
    cin >> balls[i];
    sum += balls[i];
  }

  if(k == 1){
    cout << 1 << '\n';
    return 0;
  }

  balls[k]--;
  balls[k-1]--;

  sum -= 2;
  if(sum == 0){
    cout << 1 << '\n';
    return 0;
  }
  for(int i=1;i<=sum;i++){
    product[i] = i;
  }

  for(int i=1;i<=k;i++){
    for(int j=1;j<=balls[i];j++){
      for(int k=1;k<=sum;k++){
        if(product[k]%j == 0){
          product[k] /= j;
          break;
        }
      }
    }
  }

  long long int ans = 1;
  for(int i=1;i<=sum;i++){
    ans *= product[i];
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
