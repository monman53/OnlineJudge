#include <iostream>
using namespace std;

bool check(string s){
  bool ret = false;
  if(s == "") return true;
  if(s.size() < 3){
    return false;
  }
  if(s[0] == 'm' && s[s.size()-1] == 'w'){
    for(int i=1;i<s.size()-1;i++){
      if(s[i] == 'e'){
        ret |= check(s.substr(1, i-1)) && check(s.substr(i+1, s.size()-i-2));
        if(ret){
          return true;
        }
      }
    }
  }else{
    return false;
  }
  return ret;
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
