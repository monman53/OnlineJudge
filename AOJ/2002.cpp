#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Shinamono{
  int imin, imax, jmin, jmax;
//  int count;
};

int main(){
  int n;
  cin >> n;
  for(int loop=0;loop<n;loop++){
    int h, w;
    cin >> h >> w;
    string s;
    char m[51][51];
    map<char, Shinamono> data;

    for(int i=1;i<=h;i++){
      cin >> s;
      for(int j=1;j<=w;j++){
        m[i][j] = s[j-1];
        if(s[j-1] != '.'){
          if(data.find(s[j-1]) == data.end()){
            data[s[j-1]].imin = i;
            data[s[j-1]].imax = i;
            data[s[j-1]].jmin = j;
            data[s[j-1]].jmax = j;
          }else{
            data[s[j-1]].imin = min(data[s[j-1]].imin, i);
            data[s[j-1]].imax = max(data[s[j-1]].imax, i);
            data[s[j-1]].jmin = min(data[s[j-1]].jmin, j);
            data[s[j-1]].jmax = max(data[s[j-1]].jmax, j);
          }
        }
      }
    }
    bool flag = true;
    while(flag){
      flag = false;
      for(char c='A';c<='Z';c++){
        if(data.find(c) != data.end()){
          bool rmflag = true;
          for(int i=data[c].imin;i<=data[c].imax;i++){
            for(int j=data[c].jmin;j<=data[c].jmax;j++){
              if(m[i][j] != c && m[i][j] != '#'){
                rmflag = false;
              }
            }
          }
          if(rmflag){
            flag = true;
            for(int i=data[c].imin;i<=data[c].imax;i++){
              for(int j=data[c].jmin;j<=data[c].jmax;j++){
                m[i][j] = '#';
              }
            }
            data.erase(c);
          }
//          for(int i=1;i<=h;i++){
//            for(int j=1;j<=w;j++){
//              cout << m[i][j];
//            }
//            cout << endl;
//          }
        }
      }
    }
    bool ans = true;
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        if(m[i][j] != '.' && m[i][j] != '#'){
          ans = false;
        }
      }
    }
    if(ans){
      cout << "SAFE\n";
    }else{
      cout << "SUSPICIOUS\n";
    }
  }
  return 0;
}
