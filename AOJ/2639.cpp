#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  for(int i=0;c+i*60<=(a+b)*120;i++){
    if((c+i*60)%(a+b) >= 0 && (c+i*60)%(a+b) <= a){
      cout << (c+i*60) << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
