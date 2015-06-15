#include <iostream>
#include <algorithm>
using namespace std;

int comp(int h1, int w1, int h2, int w2){
  int taikaku1 = h1*h1 + w1*w1;
  int taikaku2 = h2*h2 + w2*w2;
  if(taikaku1 > taikaku2) return 2;
  if(taikaku1 < taikaku2) return -2;
  if(h1 > h2) return 1;
  if(h1 < h2) return -1;
  return 0;
}

int main(){
  int h, w;
  while(1){
    cin >> h >> w;
    if(h == 0 && w == 0) break;

    int minh = 9999;
    int minw = 9999;
    for(int i=1;i<151;i++){
      for(int j=i+1;j<=150;j++){
        if(comp(i, j, minh, minw) < 0 && comp(i, j, h, w) > 0){
          minh = i;
          minw = j;
        }
      }
    }

    cout << minh << " " << minw << '\n';
  }
  return 0;
}
