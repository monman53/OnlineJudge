#include <iostream>
#include <queue>
using namespace std;

#define INF 9999999

int dx[6] = {1,1,0,-1,-1,0};
int dy[6] = {0,1,1,0,-1,-1};

typedef struct v{
  int x, y, value;
}V;
queue<V> v;

int main(){
  int t, n, x, y;
  while(1){
    cin >> t >> n;
//    cout << t << " " << n << '\n';
    if(t == 0 && n == 0) return 0;
    
    int map[70][70];
    for(int i=0;i<70;i++){
      for(int j=0;j<70;j++){
        map[i][j] = 0;
      }
    }
    int count=0;

    for(int i=0;i<n;i++){
      cin >> x >> y;
      map[x+35][y+35] = INF;
    }

    cin >> x >> y;
/*    
    V first;
    first.x = x+35;
    first.y = y+35;
    first.value = t+1;
    v.push(first);*/
    map[x+35][y+35] = t+1;

    for(int i=t+1;i>=2;i--){
      for(int j=0;j<70;j++){
        for(int k=0;k<70;k++){
          if(map[j][k] == i){
            for(int l=0;l<6;l++){
              int nx = j + dx[l];
              int ny = k + dy[l];
              if(map[nx][ny] != INF && i-1 > map[nx][ny]){
                map[nx][ny] = i-1;
              }
            }
          }
        }
      }
    }

/*
    while(!v.empty()){
      int cx = v.front().x;
      int cy = v.front().y;
      int cvalue = v.front().value;
      v.pop();

      if(cvalue == 1){
        continue;
      }
      map[cx][cy] = cvalue;

      for(int i=0;i<6;i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(cvalue-1 > map[nx][ny]){
          V next;
          next.x = nx;
          next.y = ny;
          next.value = cvalue-1;
          v.push(next);
          map[nx][ny] = cvalue-1;
        }
      }
    }
    */
    for(int i=0;i<70;i++){
      for(int j=0;j<70;j++){
        if(map[i][j] != INF && map[i][j] != 0){
          count++;
        }
      }
    }
    cout << count << '\n';
  }
}
