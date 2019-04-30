#include <iostream>
using namespace std;

int P, Q, R;
int wa[3][3] = {{0, 1, 2}, {1, 1, 2}, {2, 2, 2}};
int seki[3][3] = {{0, 0, 0}, {0, 1, 1}, {0, 1, 2}};

int solve(string s){
  if(s == "0") return 0;
  if(s == "1") return 1;
  if(s == "2") return 2;
  if(s == "P") return P;
  if(s == "Q") return Q;
  if(s == "R") return R;
  if(s[0] == '-') return (2 - solve(s.substr(1)));
  int balance=0;
  for(int i=0;i<s.size();i++){
    if(s[i] == '(') balance++;
    if(s[i] == ')') balance--;
    if(s[i] == '+' && balance == 1){
      return wa[solve(s.substr(1, i-1))][solve(s.substr(i+1,s.size()-i-2))];
    }
    if(s[i] == '*' && balance == 1){
      return seki[solve(s.substr(1, i-1))][solve(s.substr(i+1,s.size()-i-2))];
    }
  }
}

int ans(string s){
  int count=0;
  for(int i=0;i<3;i++){
    P = i;
    for(int j=0;j<3;j++){
      Q = j;
      for(int k=0;k<3;k++){
        R = k;
        if(solve(s) == 2){
          count++;
        }
      }
    }
  }
  return count;
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
