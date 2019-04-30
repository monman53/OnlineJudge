#include <iostream>
using namespace std;

int main(){
  int r=0, b=0, n;
  string s;

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> s;
    for(int j=0;j<s.length();j++){
      if(s[j] == 'R'){
        r++;
      }else if(s[j] == 'B'){
        b++;
      }
    }
  }
  if(r>b){
    cout << "TAKAHASHI\n";
  }else if(r<b){
    cout << "AOKI\n";
  }else{
    cout << "DRAW\n";
  }
  return 0;
}
