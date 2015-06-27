#include <iostream>
using namespace std;

int main(){
  string s;
  int n;
  cin >> s;
  cin >> n;

  cout << s[(n-1)/5] << s[(n-1)%5] << '\n';
}
