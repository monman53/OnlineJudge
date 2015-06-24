#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string spaces(int n){
  string ret="";
  for(int i=0;i<n;i++){
    ret += " ";
  }
  return ret;
}

struct Data{
  string s;
  int max;
  Data(string x, int y){
    s = x;
    max = y;
  }
};
int r, c;

vector<struct Data> before;
vector<struct Data> now;

int score(string s1, string s2){
  int ret = 0;
  for(int i=0;i<c;i++){
    if(c != c-1){
      if(s2[i] == s2[i+1] && s2[i] != ' '){
        ret += 2;
      }
    }
    if(s1[i] == s2[i] && s2[i] != ' '){
      ret += 2;
    }
  }
  return ret;
}

void test(string s, int n, string print){
  if(s.size() == 0){
    print += spaces(n);
    int mmax = 0;
    for(int i=0;i<before.size();i++){
      mmax = max(mmax, before[i].max + score(before[i].s, print));      
//      cout << before[i].s << " " << print << endl;
    }
    now.push_back(Data(print, mmax));
//    cout << print << endl;
    return;
  }
  for(int i=0;i<n-s.size()+1;i++){
    test(s.substr(1, s.size()-1), n-i-1, print + spaces(i) + s[0]);
  }
}

int main(){
  string s;
  cin >> r >> c;

  before.push_back(Data("abcdefghijklmnopqrstuvwxyz", 0));

  for(int i=0;i<r;i++){
    cin >> s;
    test(s, c, "");
    before.clear();
    before = now;
    now.clear();
  }

  int mmax = 0;
  for(int i=0;i<before.size();i++){
    mmax = max(mmax, before[i].max);
  }

  cout << mmax << '\n';

  return 0;
}
