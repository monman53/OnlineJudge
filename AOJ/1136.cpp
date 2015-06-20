#include <iostream>
using namespace std;

class Oresen{
  public:
  int m;
  int x[10];
  int y[10];
  Oresen(){}
  void rotate(){
    for(int i=0;i<m;i++){
      int nx = x[i];
      int ny = y[i];
      x[i] = -ny;
      y[i] = nx;
//      cout << "(" << x[i] << "," << y[i] << ") ";
    }
//    cout << endl;
  }
  void move(int i){
    int nx = x[i];
    int ny = y[i];
    for(int j=0;j<m;j++){
      x[j] -= nx;
      y[j] -= ny;
    }
  }
};

bool comp(Oresen o1, Oresen o2){
  if(o1.m != o2.m) return false;
  int count=0;
  for(int i=0;i<o1.m;i++){
    if(o1.x[i] == o2.x[i] && o1.y[i] == o2.y[i]){
      count++;
    }
  }
  if(count == o1.m) return true;
  count = 0;
  for(int i=0;i<o1.m;i++){
    if(o1.x[o1.m-i-1] == o2.x[i] && o1.y[o1.m-i-1] == o2.y[i]){
      count++;
    }
  }
  if(count == o1.m) return true;
  return false;;
}

int main(){
  int n, m;
  while(1){
    cin >> n;
    if(n == 0) break;

    Oresen original;

    cin >> original.m;
    for(int i=0;i<original.m;i++){
      cin >> original.x[i] >> original.y[i];
    }
    original.move(0);
    for(int i=0;i<n;i++){
//      cout << i+1 << "####\n";
      Oresen hikaku;
      cin >> hikaku.m;
      for(int j=0;j<hikaku.m;j++){
        cin >> hikaku.x[j] >> hikaku.y[j];
      }
      for(int j=0;j<hikaku.m;j+=hikaku.m-1){
        hikaku.move(j);
        for(int k=0;k<4;k++){
          hikaku.rotate();
          if(comp(original, hikaku)){
            cout << i+1 << '\n';
            j = hikaku.m;
            k = 4;
          }
        }
      }
    }
    cout << "+++++\n";
  }
  return 0;
}
