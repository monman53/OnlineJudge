#include <iostream>
using namespace std;

/*
解説参照
http://acm-icpc.aitea.net/
*/

int main(){
  int n;
  cin >> n;
  cout << (n >= 3 ? 0 : (n == 1 ? 2 : 1)) << '\n';
  return 0;
}
