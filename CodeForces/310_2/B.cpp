#include <iostream>
using namespace std;

int main(){
  int n;
  int a[1000];

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j%2 == 0){
        a[j] = (a[j]+n+1)%n;
      }else{
        a[j] = (a[j]+n-1)%n;
      }
    }
    for(int j=0;j<n;j++){
      if(a[j] != j){
        break;
      }
      if(j == n-1){
        cout << "Yes\n";
        return 0;
      }
    }
  }
  
  cout << "No\n";
  return 0;
}
