#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int n){
  vector< string > code;
  int maxlen = 0;
  for(int i = 0;i < n;++i){
    string name;
    cin >> name;
    string s;
    for(int j = 0;j < (int)name.size();++j){
      if(j == 0) s += name[j];
      if((name[j] == 'a' || name[j] == 'i' ||
	  name[j] == 'u' || name[j] == 'e' ||
	  name[j] == 'o')  && j + 1 < (int)name.size()){
	s += name[j+1];
      }
    }
    maxlen  = max(maxlen,(int)s.size()); 
    code.push_back(s);
  }
  for(int k = 1;k <= maxlen;++k){
    bool flag = true;
    for(int i = 0;flag && i < (int)code.size();++i){
      string s1;
      if((int)code[i].size() <= k)s1 = code[i];
      else s1 = code[i].substr(0,k); 
      for(int j = i+1;j < (int)code.size();++j){
	string s2;
	if((int)code[j].size() <= k)s2 = code[j];
	else s2 = code[j].substr(0,k);
	if(s1 == s2){
	  flag = false;
	  break;
	} 
      }
    }
    if(flag){
      cout << k << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void){
  int n;
  while(cin >> n,n)solve(n);
  return 0;
}
