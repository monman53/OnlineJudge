#include <iostream>
#include <algorithm>
using namespace std;

void rot(int d);

int map[100][100];
int height[100][100];
int now_dice[6];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

typedef struct v{
  int id;
  int me;
}V;

bool comp(V v1, V v2){
  return v1.me > v2.me;
}

void put(int ci, int cj){
  if(height[ci][cj] == 0){
    map[ci][cj] = now_dice[0];
    height[ci][cj]++;
    return;
  }
  V v[4];
  for(int i=0;i<4;i++){
    v[i].me = now_dice[1+i];
    v[i].id = i;
  }
  sort(v, v+4, comp);
  for(int i=0;i<4;i++){
    int ni = ci + di[v[i].id];
    int nj = cj + dj[v[i].id];
    if(height[ni][nj] < height[ci][cj] && v[i].me >= 4){
      rot(v[i].id);
      put(ni, nj);
      break;
    }
    if(i == 3){
      map[ci][cj] = now_dice[0];
      height[ci][cj]++;
      break;
    }
  }
}

int main(){
  string dir[6] = { "2354", "1463", "1265",
                    "1562", "1364", "2453"};
  int n;
  int t, f;
  while(1){
    cin >> n;
    if(n == 0) break;
    for(int i=0;i<100;i++){
      for(int j=0;j<100;j++){
        map[i][j] = -1;
        height[i][j] = 0;
      }
    }
    for(int i=0;i<n;i++){
      cin >> t >> f;
      int left = dir[t-1][(dir[t-1].find(char(f+'0'))+1)%4] - '0';
      now_dice[0] = t;
      now_dice[5] = 7-t;
      now_dice[1] = f;
      now_dice[3] = 7-f;
      now_dice[2] = left;
      now_dice[4] = 7-left;
      put(50,50);
    }
    int count[6];
    for(int j=0;j<6;j++){
      count[j] = 0;
    }
    for(int j=0;j<100;j++){
      for(int k=0;k<100;k++){
        if(map[j][k] > 0){
          count[map[j][k]-1]++;
        }
      }
    }
    for(int j=0;j<6;j++){
      cout << count[j];
      if(j != 5){
        cout << " ";
      }
    }
    cout << '\n';
  }
}

void rot(int d){
  int buf_dice[6];
  int drot[4][6] = {{1, 5, 2, 0, 4, 3},
                    {2, 1, 5, 3, 0, 4},
                    {3, 0, 2, 5, 4, 1},
                    {4, 1, 0, 3, 5, 2}};
  for(int i=0;i<6;i++) buf_dice[drot[d][i]] = now_dice[i];
  for(int i=0;i<6;i++) now_dice[i] = buf_dice[i];
}
