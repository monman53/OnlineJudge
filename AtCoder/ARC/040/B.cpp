#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, r;
  string s;
  int time=0;

  cin >> n >> r;
  cin >> s;
  
  int start;
  for(int i=n-1;i>=0;i--){
    if(s[i] == '.'){
      time+=max(0,i-r+1);
      break;
    }
  }

  for(int i=n-1;i>=0;){
    if(s[i] == '.'){
      i -= r;
      time++;
    }else if(s[i] == 'o'){
      i--;
    }
  }
  
  cout << time << '\n';

  return 0;
}
