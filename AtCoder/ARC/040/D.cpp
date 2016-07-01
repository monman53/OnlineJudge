#include <iostream>
using namespace std;

int n;
char map[400][400];
bool came[400][400];
int walkable;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

bool calc(int ci, int cj, int count,int dir){
  came[ci][cj] = true;
//      cout << ci << " " << cj << " " << count << " " << dir << "\n";
  if(count==1){
    return true;
  }

  bool ret=false;

  for(int i=0;i<2;i++){
    int ni = ci + di[(1 - (dir%2)) + i*2];
    int nj = cj + dj[(1 - (dir%2)) + i*2];
    if(ni >= 0 && ni < n && nj >= 0 && nj < n){

//      cout << ci << " " << cj << " "  << came[ni][nj] << '\n';
      if(map[ni][nj] == '.' && !came[ni][nj]){
//        cout << "kita2\n\n";
        //ret = (ret || calc(ni, nj, count-1, 1-(dir%2)+i));
        ret |= calc(ni, nj, count-1, 1 - (dir%2) + i*2);
      }
    }
  }
  came[ci][cj] = false;
  return ret;
}

int main(){
  string s;
  int starti, startj;

  walkable = 0;
  
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> s;
    for(int j=0;j<s.length();j++){
      if(s[j] == '#'){
        map[i][j] = '#';
      }else if(s[j] == '.'){
        map[i][j] = '.';
        walkable++;
      }else{
        map[i][j] = '.';
        starti = i;
        startj = j;
      }
      came[i][j] = false;
    }
  }
  bool ans = false;
  for(int i=0;i<4;i++){
    ans = (ans || calc(starti, startj, walkable, 2));
  }
  if(ans){
    cout << "POSSIBLE\n";
  }else{
    cout << "IMPOSSIBLE\n";
  }

}
