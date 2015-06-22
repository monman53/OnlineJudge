#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

int main(){
  int n, m;
  string s;
  
  cin >> n;

  map<string, vector<bool> > data;

  for(int i=0;i<n;i++){
    vector<bool> buf(256, false);
    int from, to;
    cin >> s;
    cin >> from >> to;
    for(int j=from;j<=to;j++){
      buf[j] = true;
    }
    data[s] = buf;
  }
  
  cin >> m;

  stack<vector<bool> > rpn;

  for(int i=0;i<m;i++){
    cin >> s;
    if(s == "+" || s == "-" || s == "*" || s == "/"){
      vector<bool> b = rpn.top();
      rpn.pop();
      vector<bool> a = rpn.top();
      rpn.pop();
      
      vector<bool> buf(256, false);

      for(int j=0;j<256;j++){
        for(int k=0;k<256;k++){
          if(a[j] && b[k]){
            if(s == "+") buf[(j+k)%256] = true;
            if(s == "-") buf[(j-k+256)%256] = true;
            if(s == "*") buf[(j*k)%256] = true;
            if(s == "/"){
              if(k == 0){
                cout << "error\n";
                return 0;
              }else{
                buf[(j/k)%256] = true;
              }
            }
          }
        }
      }
      rpn.push(buf);
    }else if(data.find(s) != data.end()){
      rpn.push(data[s]);
    }else{
      int n=0;
      for(int i=s.size()-1,j=1;i>=0;i--,j*=10){
        n += (s[i] - '0')*j;
      }
      vector<bool> buf(256, false);
      buf[n] = true;
      rpn.push(buf);
    }
  }
  cout << "correct\n";
  return 0;
}
