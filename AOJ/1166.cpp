#include <iostream>
#include <stack>
using namespace std;

#define INF 99999999

int w, h;
int mmin[30][30];
int kabe[60][30];
int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

class V{
  public:
  int min;
  int i, j;
  V(){};
  V(int x, int y, int z){i=x;j=y;min=z;}
};

bool movable(int ci, int cj, int dir){
  int ni = ci + di[dir];
  int nj = cj + dj[dir];
  if(ni < 0 || ni >= h || nj < 0 || nj >= w){
    return false;
  }
  int kdi[] = {0, -1, 0, 1};
  int kdj[] = {0, 0, -1, 0};
  int kni = ci*2 + kdi[dir];
  int knj = cj + kdj[dir];
  if(kabe[kni][knj] == 1){
    return false;
  }
  return true;
}

int main(){
  while(1){
    cin >> w >> h;
    if(w == 0) break;

    for(int i=0;i<2*h-1;i++){
      for(int j=0;j<w-(1-i%2);j++){
        cin >> kabe[i][j];
      }
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        mmin[i][j] = INF;
      }
    }
    
    stack<V> s;
    s.push(V(0,0,1));
    while(!s.empty()){
      int ci = s.top().i;
      int cj = s.top().j;
      int cmin = s.top().min;
      s.pop();

      if(cmin < mmin[ci][cj]){
        mmin[ci][cj] = cmin;
      }else{
        continue;
      }

      for(int i=0;i<4;i++){
        int ni = ci + di[i];
        int nj = cj + dj[i];
        if(movable(ci, cj, i)){
          s.push(V(ni, nj, cmin+1));
        }
      }
    }
    if(mmin[h-1][w-1] == INF){
      cout << 0 << '\n';  
    }else{
      cout << mmin[h-1][w-1] << '\n';
    }
  }
}
