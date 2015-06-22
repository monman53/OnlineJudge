#include <iostream>
using namespace std;

bool used[256];
bool pf;
int total, count;

void print(string s){
  if(pf && (count < 5 || count >= total-5)){
    cout << s << '\n';
  }
  count++;
}

int ans(string s, int i){
  int ret = 0;

  if(used[s[i]] && used[s[i]+1]){
    if(i == s.size()-1){
      ret += 1;
      print(s);
    }else{
      ret += ans(s, i+1);
    }
  }else if(used[s[i]] && !used[s[i]+1]){
    if(i == s.size()-1){
      if(s[i] != 'z'){
        ret += 2;
        print(s);
        s[i]++;
        print(s);
      }else{
        ret += 1;
        print(s);
      }
    }else{
      ret += ans(s, i+1);
      if(s[i] != 'z'){
        s[i]++;
        used[s[i]] = true;
        ret += ans(s, i+1);
        used[s[i]] = false;
        s[i]--;
      }
    }
  }else if(!used[s[i]] && !used[s[i]+1]){
    if(i == s.size()-1){
      if(s[i] == 'a'){
        ret += 1;
        print(s);
      }
      if(s[i] != 'z'){
        ret += 1;
        s[i]++;
        print(s);
      }
    }else{
      if(s[i] == 'a'){
        used['a'] = true;
        ret += ans(s, i+1);
        used['a'] = false;
      }
      if(s[i] != 'z'){
        s[i]++;
        used[s[i]] = true;
        ret += ans(s, i+1);
        used[s[i]] = false;
        s[i]--;
      }
    }
  }else if(!used[s[i]] && used[s[i]+1]){
    if(i == s.size()-1){
      if(s[i] == 'a'){
        ret += 1;
        print(s);
      }
    }else{
      if(s[i] == 'a'){
        used['a'] = true;
        ret += ans(s, i+1);
        used['a'] = false;
      }
    }
  }

  return ret;
}

int main(){
  string s;
  while(1){
    cin >> s;
    if(s == "#") break;
    
    for(int i=0;i<256;i++) used[i] = false;
    pf = false;
    cout << (total = ans(s, 0)) << '\n';
    
    pf = true;
    count = 0;
    ans(s, 0);
  }

  return 0;
}
