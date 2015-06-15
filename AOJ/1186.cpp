#include <iostream>
using namespace std;

int main(){
  int h, w;
  while(1){
    cin >> h >> w;
    if(h == 0 || w == 0) break;
    int minh = h;
    int minw = w;
    if(w == 1){
      cout << (h+1) << " " << w << '\n';
    }else{
      for(int nh=h;nh<=w;nh++){
        for(int nw=w;nw>nh;nw--){
          if(nh != h && nw != w){
            if(nh*nh + nw*nw < minh*minh + minw*minw){
              minh = nh;
              minw = nw;
            }else if(nh*nh + nw*nw = minh*minh + minw*minw){
              if(nh < minh
            }
          }
        }
      }
    }
  }
  return 0;
}
