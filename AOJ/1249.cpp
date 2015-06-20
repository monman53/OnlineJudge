#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, p;
int peg[7][7][7];
int peg_top[7][7];
int di[16] = {0, 0, 1, 0, 1, 1, 1, 0, 1,-1,-1, 1, 1,-1,-1,1};
int dj[16] = {0, 1, 0, 1, 0, 1, 1,-1, 0, 1, 1,-1, 1,-1,1,-1};
int dk[16] = {1, 0, 0, 1, 1, 0, 1, 1,-1, 0, 1, 1,-1,1,-1,-1};

void put(int i, int j, int color){
//  cout << peg_top[i][j];
  peg[i][j][peg_top[i][j]] = color;
  peg_top[i][j]++;
}

int check(int color){
  int mmax = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        if(peg[i][j][k] == color){
          for(int l=0;l<16;l++){
            int count = 0;
            for(int h=0;h<m;h++){
              int ni = i + di[l]*h;
              int nj = j + dj[l]*h;
              int nk = k + dk[l]*h;
              if(ni >= 0 && ni < n &&
                 nj >= 0 && nj < n && 
                 nk >= 0 && nk < n){
                if(peg[ni][nj][nk] == color){
                  count++;
                }else{
                  break; 
                }
              }
            }
            //cout << count;
            mmax = max(mmax, count);
          }
        }
        //cout << peg[i][j][k] << " ";
      }
      //cout << endl;
    }
  }
//  cout << mmax << endl;
  return mmax;
}

int main(){
  int x, y;
  while(1){
    cin >> n >> m >> p;
    if(m == 0) break;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        peg_top[i][j] = 0;
        for(int k=0;k<n;k++){
          peg[i][j][k] = -1;
        }
      }
    }
    bool end = false;
    vector<int> xl;
    vector<int> yl;
    for(int i=0;i<p;i++){
      int a,b;
      cin >> a >> b;
      xl.push_back(a);
      yl.push_back(b);
    }
    for(int i=0;i<p;i++){
      put(xl[i]-1, yl[i]-1, i%2);
      if(check(i%2) >= m){
        cout << (i%2 ? "White" : "Black") << " " << (i+1) << '\n';
        break;
      }else if(i == p-1){
        cout << "Draw\n";
      }
    }
  }
  return 0;
}
