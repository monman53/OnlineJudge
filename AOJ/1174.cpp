#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int h, w, c, mmax;
string s;
int data[8][8];
int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

void paint(int ci, int cj, int to){
  int from = data[ci][cj];
  data[ci][cj] = to;
  for(int i=0;i<4;i++){
    int ni = ci + di[i];
    int nj = cj + dj[i];
    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
      if(data[ni][nj] == from){
        paint(ni, nj, to);
      }
    }
  }
}

int mcount(int ci, int cj, int color){
  int n=1;
  data[ci][cj] = 0;
  for(int i=0;i<4;i++){
    int ni = ci + di[i];
    int nj = cj + dj[i];
    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
      if(data[ni][nj] == color){
        n += mcount(ni, nj, color);
      }
    }
  }
  return n;
}

void ans(int n){
  int datab[8][8];
  if(n==1){
    if(data[0][0] != c){
      paint(0, 0, c);
    }
    mmax = max(mmax, mcount(0, 0, c));
  }else{
    for(int i=1;i<=6;i++){
      for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
          datab[j][k] = data[j][k];
        }
      }
      if(i!=data[0][0]){
        paint(0, 0, i);
        ans(n-1);
      }
      for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
          data[j][k] = datab[j][k];
        }
      }
    }
  }
}

int main(){
  while(1){
    cin >> h >> w >> c;
    if(h == 0) break;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin >> data[i][j];
      }
    }

    mmax = 0;
    ans(5);

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
//        cout << data[i][j];
      }
//      cout << '\n';
    }
    cout << mmax << '\n';
  }
  return 0;
}
