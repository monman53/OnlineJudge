#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  int d, e;
    
  double mmin;

  while(1){
    cin >> d >> e;
    if(d == 0 && e == 0) break;
    mmin = 99999999;

    for(int x=0;x<=d;x++){
      int y=d-x;
      mmin = min(mmin, abs(sqrt(x*x + y*y)-e));
    }
    cout << mmin << '\n';
  }

  return 0;
}
