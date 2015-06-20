#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
  int n, t, l, b, x;
  while(1){
    cin >> n >> t >> l >> b;
    if(n == 0) break;
  
    int data[101];
    double prob[101][101];
    for(int i=0;i<=n;i++){
      data[i] = 0;
      prob[i][0] = 0;
    }
    for(int i=1;i<=t;i++){
      prob[n][i] = 0;
    }
    prob[n][0] = 1;

    for(int i=0;i<l;i++){
      cin >> x;
      data[x] = 1;
    }
    for(int i=0;i<b;i++){
      cin >> x;
      data[x] = 2;
    }
   
    for(int i=1;i<=t;i++){
      for(int j=0;j<n;j++){
        prob[j][i] = 0;
        for(int k=1;k<=6;k++){
          int nj;
          if(j+k>n){
            nj = n-(j+k-n);
          }else{
            nj = j+k;
          }

          if(data[nj] == 2){
            prob[j][i] += prob[0][i-1]/6;
          }else if(data[nj] == 1){
            if(i != 1){
              prob[j][i] += prob[nj][i-2]/6;
            }
          }else{
            prob[j][i] += prob[nj][i-1]/6;
          }
        }
      }
    }
    double sum = 0;
    for(int i=1;i<=t;i++){
      sum += prob[0][i];
    }
    printf("%f\n", sum);
  }
  return 0;
}
