#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int INF = 1 << 29;
typedef pair<int, int> Pair;

int main(){
  int w, h, n;
  int sx, sy, gx, gy;
  int x, y, t;
  string s;
  cin >> w >> h >> n;
  cin >> sx >> sy >> gx >> gy;
  vector<vector<int> > count(h*2+1, vector<int>(w+1, 0));
  
  for(int i=0;i<n;i++){
    cin >> x >> y;
    cin >> t >> s;
    string buf="";
    for(int j=0;j<t;j++) buf += s;
    s = buf;
    for(int j=0;j<s.size();j++){
      switch(s[j]){
      case 'U':
        if(y != 0){
          count[y*2][x]++;
          y--;
        }
        break;
      case 'D':
        if(y != h-1){
          count[y*2+2][x]++;
          y++;
        }
        break;
      case 'L':
        if(x != 0){
          count[y*2+1][x]++;
          x--;
        }
        break;
      case 'R':
        if(x != w-1){
          count[y*2+1][x+1]++;
          x++;
        }
        break;
      }
    }
  }
  
  vector<int> cost((h+1)*(w+1), INF);
  priority_queue<Pair, vector<Pair>, greater<Pair> > q;
  cost[(w+1)*sy + sx] = 0;
  q.push(Pair(0, (w+1)*sy + sx));
  int dy[] = {0, -1, 0, 1};
  int dx[] = {1, 0, -1, 0};
  int cdx[] = {0, 0, -1, 0};
  int cdy[] = {0, -1, 0, 1};

  while(!q.empty()){
    Pair c = q.top();
    q.pop();
    int cy = c.second/(w+1);
    int cx = c.second%(w+1);
    if(cost[c.second] < c.first) continue;
    for(int i=0;i<4;i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      int cny = cy*2 + cdy[i];
      int cnx = cx + cdx[i];
      if(ny >= 0 && ny <= h && nx >= 0 && nx <= w){
        int cos = c.first + count[cny][cnx];
        if(cos < cost[(w+1)*ny + nx]){
          cost[(w+1)*ny + nx] = cos;
          q.push(Pair((cos), (w+1)*ny + nx));
        }
      }
    }
  }

  cout << cost[(w+1)*gy + gx] << '\n';

//  for(int i=0;i<2*h;i++){
//    for(int j=0;j<w;j++){
//      cout << count[i][j] << " ";
//    }
//    cout << endl;
//  }


  return 0;
}
