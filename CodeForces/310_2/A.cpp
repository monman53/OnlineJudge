#include <iostream>
using namespace std;

int main(){
  int n;
  string s;

  cin >> n >> s;

  int one=0;
  int zero=0;

  for(int i=0;i<n;i++){
    if(s[i] == '0'){
      if(one > 0){
        one--;
      }else{
        zero++;
      }
    }else{
      if(zero > 0){
        zero--;
      }else{
        one++;
      }
    }
  }

  cout << (zero+one) << '\n';
}
