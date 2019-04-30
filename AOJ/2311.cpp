#include <iostream>
#include <algorithm>
using namespace std;

int map[8][8];
int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int put(int ci, int cj, int cc, bool flag){
  int ret = 0;
  if(map[ci][cj] != -1){
    return ret;
  }
  for(int i=0;i<8;i++){
    int count=0;
    for(int j=1;;j++){
      int ni = ci + di[i]*j;
      int nj = cj + dj[i]*j;
      if(ni >= 0 && ni < 8 && nj >= 0 && nj < 8){
        if(map[ni][nj] == -1){
          count =0;
          break;
        }else if(map[ni][nj] != cc && map[ni][nj] != -1){
          count++;
        }else if(map[ni][nj] == cc && flag){
          for(int k=0;k<j;k++){
            map[ci+di[i]*k][cj+dj[i]*k] = cc;
          }
          break;
        }else{
          break;
        }
      }else{
        count = 0;
        break;
      }
    }
    ret += count;
  }
  return ret;
}

int main(){
  string s;
  for(int i=0;i<8;i++){
    cin >> s;
    for(int j=0;j<8;j++){
      if(s[j] == 'o') map[i][j] = 1;
      if(s[j] == 'x') map[i][j] = 0;
      if(s[j] == '.') map[i][j] = -1;
    }
  }

  bool putf1, putf2;

  while(1){
    int pi, pj;
    int mmax, buf;

    mmax = 1;
    putf1 = false;
    for(int i=7;i>=0;i--){
      for(int j=7;j>=0;j--){
        if((buf = put(i, j, 1, false)) >= mmax){
          mmax = buf;
          pi = i;
          pj = j;
          putf1 = true;
        }
      }
    }
    if(putf1){
      put(pi, pj, 1, true);
    }

    mmax = 1;
    putf2 = false;
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        if((buf = put(i, j, 0, false)) >= mmax){
          mmax = buf;
          pi = i;
          pj = j;
          putf2 = true;
        }
      }
    }
    if(putf2){
      put(pi, pj, 0, true);
    }

    if(!putf1 && !putf2){
      break;
    }
  }

  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(map[i][j] == 1) cout << 'o';
      if(map[i][j] == 0) cout << 'x';
      if(map[i][j] == -1) cout << '.';
    }
    cout << '\n';
  }

  return 0;
}
