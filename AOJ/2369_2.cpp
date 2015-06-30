#include <iostream>
#include <stack>
using namespace std;

int main(){
  string s;
  cin >> s;

  stack<char> data;
  for(int i=0;i<s.size();i++){
    if(data.size() == 0){
      data.push(s[i]);
      continue;
    }
    char cc;
    switch(s[i]){
    case 'm':
    case 'e':
      data.push(s[i]);
      break;
    case 'w':
      cc = data.top();
      if(cc == 'e'){
        data.pop();
      }else{
        cout << "Rabbit\n";
        return 0;
      }
      cc = data.top();
      if(cc == 'm'){
        data.pop();
      }else{
        cout << "Rabbit\n";
        return 0;
      }
      if(data.size() == 0 && i != s.size()-1){
        cout << "Rabbit\n";
        return 0;
      }
      break;
    }
  }

  if(data.size() == 0){
    cout << "Cat\n";
  }else{
    cout << "Rabbit\n";
  }
  return 0;
}
