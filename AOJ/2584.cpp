#include <iostream>
#include <string>
using namespace std;

string reverse(string s){
  string ret="";
  for(int i=0;i<s.size();i++){
    ret += s[s.size() - i - 1];
  }
  return ret;
}

string ans(string s){
  string ret="";
  int leftc=0, rightc=0;
  int diff=0;
  int j=0;

  for(int i=0;i<s.size();i++){
    switch(s[i]){
    case '[':
      j=0;
      leftc++;
      while(leftc != rightc){
        j++;
        if(s[i+j] == '[') leftc++;
        if(s[i+j] == ']') rightc++;
      }
      ret += reverse(ans(s.substr(i+1,j-1)));
      i += j;
      break;
    case '+':
      diff++;
      diff = diff%26;
      break;
    case '-':
      diff--;
      if(diff < 0) diff = 25;
      break;
    case '?':
      ret += 'A';
      diff=0;
      break;
    default:
      ret += 'A' + (s[i] + diff - 'A')%26;
      diff=0;
      break;
    }
  }

  return ret;
}

int main(){
  string s;

  while(1){
    cin >> s;
    if(s == ".") break;
    cout << ans(s) << '\n';
  }

  return 0;
}
