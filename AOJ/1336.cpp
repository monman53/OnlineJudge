#include <iostream>
#include <vector>
using namespace std;

struct Ant{
  int id, d;
  Ant(int x, int y){
    id = x;
    d = y;
  }
};

int main(){
  int n, l;
  while(1){
    cin >> n >> l;
    if(n == 0 && l == 0) break;

    vector<vector<Ant> > data(l);
    char d;
    int x;

    for(int i=0;i<n;i++){
      cin >> d >> x;
      data[x].push_back(Ant(i+1, (d == 'R' ? 1 : -1)));
    }
    
    int time=0;
    while(1){
      vector<vector<Ant> > next(l);
      next[0] = data[0];
      //cout << time << ": ";
      for(int i=l-1;i>=1;i--){
        int count = (int)data[i].size();
        //cout << count << " ";
        if(count == 2){
          if(data[i][0].d == -1){
            next[(i-data[i][0].d)%l].push_back(Ant(data[i][0].id, -data[i][0].d));
            next[(i-data[i][1].d)%l].push_back(Ant(data[i][1].id, -data[i][1].d));
          }else{
            next[(i+data[i][0].d)%l].push_back(Ant(data[i][0].id, data[i][0].d));
            next[(i+data[i][1].d)%l].push_back(Ant(data[i][1].id, data[i][1].d));
          }
        }else if(count == 1){
          next[(i+data[i][0].d)%l].push_back(Ant(data[i][0].id, data[i][0].d));
        }
      }
      //cout << endl;
      data = next;
      time++;
      if((int)data[0].size() == n) break;
    }
    cout << time << " " << data[0][n-1].id <<endl;
  }
  return 0;
}
