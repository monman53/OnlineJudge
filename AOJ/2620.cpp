#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
  int id, min;
  bool operator<(const Node &a) const {
    return min < a.min;
  }
};

int main(){
  int w, h, n;
  int sx, sy, gx, gy;
  int x, y, t;
  string s;
  cin >> w >> h >> n;
  cin >> sx >> sy >> gx >> gy;
  vector<vector<int> > count(h, vector<int>(w, 0));
  


  return 0;
}
