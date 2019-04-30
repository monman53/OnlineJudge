#include <iostream>
using namespace std;

#define INF 9999999

int dx[6] = {1,1,0,-1,-1,0};
int dy[6] = {0,1,1,0,-1,-1};

int main(){
  int t, n, x, y;
  while(1){
    cin >> t >> n;
    if(t == 0 && n == 0) return 0;
    
    int map[140][140];
    for(int i=0;i<140;i++){
      for(int j=0;j<140;j++){
        map[i][j] = 0;
      }
    }
    int count=1;

    for(int i=0;i<n;i++){
      cin >> x >> y;
      map[x+70][y+70] = INF;
    }

    cin >> x >> y;
    
    map[x+70][y+70] = t+1;

    for(int i=t+1;i>=2;i--){
      for(int j=0;j<140;j++){
        for(int k=0;k<140;k++){
          if(map[j][k] == i){
            for(int l=0;l<6;l++){
              int nx = j + dx[l];
              int ny = k + dy[l];
              if(map[nx][ny] == 0){
                map[nx][ny] = i-1;
                count++;
              }
            }
          }
        }
      }
    }
    cout << count << '\n';
  }
}
