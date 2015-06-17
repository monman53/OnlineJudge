#include <iostream>
using namespace std;

void change(string *s, char c){
  string buf="";
  int size = (*s).size();
  switch (c){
  case 'J':
    buf = (*s)[size-1] + (*s).substr(0, size-1);
    break;
  case 'C':
    buf = (*s).substr(1, size-1) + (*s)[0];
    break;
  case 'E':
    buf += (*s).substr(size/2 + (size%2 ? 1 : 0), size/2);
    if(size%2){
      buf += (*s)[size/2];
    }
    buf += (*s).substr(0, size/2);
    break;
  case 'A':
    for(int i=size-1;i>=0;i--){
      buf += (*s)[i];
    }
    break;
  case 'P':
    for(int i=0;i<size;i++){
      if((*s)[i] == '0') (*s)[i] = '9';
      else if((*s)[i] >= '1' && (*s)[i] <= '9') (*s)[i]--;
    }
    return;
  case 'M':
    for(int i=0;i<size;i++){
      if((*s)[i] == '9') (*s)[i] = '0';
      else if((*s)[i] >= '0' && (*s)[i] <= '8') (*s)[i]++;
    }
    return;
  }
  (*s) = buf;
}

int main(){
  string s, order;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> order >> s;
    for(int j=order.size()-1;j>=0;j--){
      change(&s, order[j]);
    }
    cout << s <<endl;
  }

  return 0;
}
