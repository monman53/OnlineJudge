#include <iostream>
#include <set>
using namespace std;

int main(){
  int h, w;
  string s;

  while(1){
    cin >> h >> w;
    if(h == 0) break;
    
    char map[10][20];
    int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    set<string> data;
    string ans = "a";
    
    for(int i=0;i<h;i++){
      cin >> s;
      for(int j=0;j<w;j++){
        map[i][j] = s[j];
      }
    }

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        for(int k=0;k<8;k++){
          string ss = "";
          ss += map[i][j];
          for(int l=1;;l++){
            int ni = (i + di[k]*l + h*l)%h;
            int nj = (j + dj[k]*l + w*l)%w;
            if(ni == i && nj == j) break;
            ss += map[ni][nj];
            if(data.count(ss) >= 1 && ss.size() >= ans.size()){
              if(ans.size() != ss.size() || ans.size() == ss.size() && ss <= ans){
                ans = ss;
              }
            }
            data.insert(ss);
          }
//          cout << ss << endl;
        }
      }
    }

    if(ans != "a"){
      cout << ans << '\n';
    }else{
      cout << "0\n";
    }
  }

  return 0;
}
