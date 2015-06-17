#include <iostream>
using namespace std;

int w, h;
int mcount;
int bcount, wcount;
char map[50][50];
bool kita[50][50];
int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

void ans(int ci, int cj){
  if(kita[ci][cj]) return;
  kita[ci][cj] = true;
  if(map[ci][cj] == 'B'){
    bcount++;
    return;
  }
  if(map[ci][cj] == 'W'){
    wcount++;
    return;
  }
  map[ci][cj] = 'X';
  mcount++;
  for(int i=0;i<4;i++){
    int ni = ci + di[i];
    int nj = cj + dj[i];
    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
      ans(ni, nj);
    }
  }
}

int main(){
  int bans, wans;
  string s;
  while(1){
    cin >> w >> h;
    if(w == 0) break;
    for(int i=0;i<h;i++){
      cin >> s;
      for(int j=0;j<w;j++){
        map[i][j] = s[j];
      }
    }
    bans = 0;
    wans = 0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(map[i][j] == '.'){
          bcount = 0;
          wcount = 0;
          mcount = 0;
          for(int k=0;k<h;k++){
            for(int l=0;l<w;l++){
              kita[k][l] = false;
            }
          }
          ans(i, j);
          if(bcount > 0 && wcount == 0){
            bans += mcount;
          }else if(bcount == 0 && wcount > 0){
            wans += mcount;
          }
        }
      }
    }
    cout << bans << " " << wans << '\n';
  }
  return 0;
}
