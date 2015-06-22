#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int r, m, xl, xr, h;

  while(1){
    cin >> r >> m;
    if(r == 0 && m == 0) break;
    
    int f[41][2];
    int data[40];
    for(int i=0;i<=40;i++){
      f[i][0] = f[i][1] = r;
      if(i != 40){
        data[i] = 0;
      }
    }

    for(int i=0;i<m;i++){
      cin >> xl >> xr >> h;
      for(int i=20+xl;i<20+xr;i++){
        data[i] = max(data[i], h);
      }
    }
    f[0][0] = r;
    f[0][1] = r + data[0];
    f[40][0] = r;
    f[40][1] = r + data[39];
    for(int i=1;i<40;i++){
      f[i][0] = max(data[i-1], data[i]) + r;
      f[i][1] = min(data[i-1], data[i]) + r;
    }

    double ans = 9999999;
    /*for(int i=0;i<41;i++){
      cout << i-20 << "\t" << f[i][0] << " " << f[i][1] << endl;
    }*/
    for(int i=20-r+1;i<20+r;i++){
      for(int j=0;j<2;j++){
        ans = min(ans, f[i][j] - sqrt(r*r - (i-20)*(i-20)));
//        if(ans < double(f[i]) - double(sqrt(double(r*r - (i-20)*(i-20))))){
//          ans = double(f[i]) - sqrt(r*r - (i-20)*(i-20));
//        }
      }
    }
    printf("%f\n", ans);
  }
}
