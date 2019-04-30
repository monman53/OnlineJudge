#include <iostream>
using namespace std;

int main(){
  int n, k;
  int m, a;

  cin >> n >> k;

  int ans = n-1;

  for(int i=0;i<k;i++){
    cin >> m;
    int a[m];
    int count;
    int first;
    int last;
    ans += m-1;
    for(int j=0;j<m;j++){
      cin >> a[j];
      if(j!=0){
        if(a[j-1] == a[j]-1){
          count++;
          last = a[j];
          if(j == m-1 && (first == 1 || last == n)){
            ans -= 2*count;
          }
        }else{
          if(count!=0){
            if(first == 1 || last == n){
              ans -= 2*count;
            }
          }
          count=0;
          first = a[j];
        }
      }else{
        first = a[j];
        count=0;
      }
    }
  }
  
  cout << ans << '\n';

  return 0;
}
