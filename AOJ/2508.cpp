#include <iostream>
using namespace std;

int count(char c){
  if(c >= 'a' && c <= 'z'){
    return c-'a';
  }
  if(c >= 'A' && c <= 'Z'){
    return c-'A'+26;
  }
  return -1;
}

int main(){
  string list = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  int n;
  int k[100];
  string s;
  while(1){
    cin >> n;
    if(n == 0) break;
    for(int i=0;i<n;i++){
      cin >> k[i];
    }
    cin >> s;
    for(int i=0;i<s.size();i++){
      cout << list[(count(s[i])-k[i%n]+52)%52];
    }
    cout << '\n';

  }
  return 0;
}
