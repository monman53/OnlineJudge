#include <iostream>
using namespace std;

int main(){
  int n, k, p;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> k >> p;
    cout << ((k%p) ? k%p : p) << '\n';
  }
  return 0;
}
