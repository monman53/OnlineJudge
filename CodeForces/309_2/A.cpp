#include <iostream>
using namespace std;

int main(){
  string s;

  cin >> s;

  int count = 0;
  for(int i=0;i<s.size();){
    int j=i;
    while(s[j] == s[i]){
      count++;
      j++;
    }
    i=j;
  }

  cout << ((s.size()+1)*26-count) << '\n';

  return 0;
}
