#include <iostream>
using namespace std;

int I;

int ston(string s){
  int ret = 0;
  for(int i=s.size()-1,j=1;i>=0;i--,j*=10){
    ret += (s[i] - '0')*j;
  }
  return ret;
}

string solve(string s){
  string ret="";

  for(int i=0;i<s.size();){
    if(s[i] >= 'A' && s[i] <= 'Z'){
      ret += s[i];
      i++;
    }else if(s[i] >= '0' && s[i] <= '9'){
      string number="";
      for(;s[i] >= '0' && s[i] <= '9';i++){
        number = number + s[i];
      }
      int n = ston(number);
      string repeat="";
      if(s[i] == '('){
        int start = i+1;
        i++;
        int balance = 1;
        for(;balance != 0;i++){
          if(s[i] == '(') balance++;
          if(s[i] == ')') balance--;
        }
        repeat = solve(s.substr(start, i-1-start));
      }else{
        repeat = s[i];
        i++;
      }
      for(int j=0;j<n;j++){
        ret += repeat;
        if(ret.size() > I){
          break;
        }
      }
//      cout << ret << endl;
    }
    if(ret.size() > I) break;
  }

  return ret.substr(0, I+1);
}

int main(){
  string s;
  while(1){
    cin >> s >> I;
    if(s == "0") break;

    string ans = solve(s);
    
    if(ans.size() <= I){
      cout << "0\n";
    }else{
      cout << ans[I] << '\n';
    }
  }
}
