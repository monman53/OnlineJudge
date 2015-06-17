#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Packet{
  public:
  int t, s, d;
  Packet(){}
  Packet(int i, int j, int k){
    t = i;
    s = j;
    d = k;
  }
};

bool sort_comp(Packet p1, Packet p2){
  return p1.t < p2.t;
}

int main(){
  int n, m;
  while(1){
    cin >> n >> m;
    if(n == 0) break;

    bool infected[n];
    for(int i=0;i<n;i++){
      infected[i] = false;
    }
    infected[0] = true;
    int count = 0;
    Packet data[m];
    for(int i=0;i<m;i++){
      cin >> data[i].t >> data[i].s >> data[i].d;
    }
    sort(data, data+m, sort_comp);

    for(int i=0;i<m;i++){
      if(infected[data[i].s-1]){
        infected[data[i].d-1] = true;
      }
    }
    for(int i=0;i<n;i++){
      if(infected[i]) count++;
    }
    cout << count << '\n';
  }
  return 0;
}
