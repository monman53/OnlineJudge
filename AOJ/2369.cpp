#include <iostream>
using namespace std;

bool check(string s){
  if(s == "") return true;
  if(s[0] == 'm' && s[s.size()-1] == 'w'){
    for(int i=1;i<s.size()-1;i++){
      if(s[i] == 'e'){
        if(check(s.substr(1, i-1)) && check(s.substr(i+1, s.size()-i-2))){
          return true;
        }
      }
    }
    return false;
  }else{
    return false;
  }
}

int main(){
  string s;
  cin >> s;
  if(check(s)){
    cout << "Cat\n";
  }else{
    cout << "Rabbit\n";
  }
  return 0;
}
