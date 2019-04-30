#include <iostream>
using namespace std;



int main(){
  bool hmax[200001];
  bool wmax[200001];
  int n, w, h;
  int x, y, r;
  int hcount = 0;
  int wcount = 0;
  
  cin >> n >> w >> h;

  for(int i=0;i<=h*2;i++){
    hmax[i] = -1;
  }
  for(int i=0;i<=w*2;i++){
    wmax[i] = -1;
  }
  cout << n << " " << w << " " << h << endl;;  
  for(int i=0;i<n;i++){
    cout << i << endl;
    cin >> x >> y >> r;
    if(r*2 > wmax[2*x] && wcount != w*2+1){
      for(int j=0;j<=2*r;j++){
        if(x*2+j <= 2*w){
          if(2*r-j > wmax[2*x+j]){
            if(wmax[2*x+j] == -1) wcount++;
            wmax[2*x+j] = 2*r-j;
          }else{
            break;
          }
        }else{
          break;
        }
      }
      for(int j=0;j<=2*r;j++){
        if(x*2-j >= 0){
          if(2*r-j > wmax[2*x-j]){
            if(wmax[2*x-j] == -1) wcount++;
            wmax[2*x-j] = 2*r-j;
          }else{
            break;
          }
        }else{
          break;
        }
      }
    }
    
    if(r*2 > hmax[2*y] && hcount != 2*h+1){
      for(int j=0;j<=2*r;j++){
        if(y*2+j <= 2*h){
          if(2*r-j > hmax[2*y+j]){
            if(wmax[2*y+j] == -1) hcount++;
            hmax[2*y+j] = 2*r-j;
          }else{
            break;
          }
        }else{
          break;
        }
      }
      for(int j=0;j<=2*r;j++){
        if(y*2-j >= 0){
          if(2*r-j > hmax[2*y-j]){
            hmax[2*y-j] = 2*r-j;
          }else{
            break;
          }
        }else{
          break;
        }
      }
    }
  }
/*
  bool wflag=true;
  bool hflag=true;
 
  for(int i=0;i<=h*2;i++){
    if(hmax[i] == -1){
      hflag = false;
      break;
    }
  }
  for(int i=0;i<=w*2;i++){
    if(wmax[i] == -1){
      wflag = false;
      break;
    }
  }
*/

  if(hcount == h*2+1 || wcount == w*2+1){
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }

  return 0;
}
