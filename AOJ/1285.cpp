#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n, w, v;
  while(1){
    cin >> n >> w;
    if(n == 0 && w == 0) break;
    int data[11];
    for(int i=0;i<11;i++){
      data[i] = 0;
    }
    int wmax=0;
    int datamax=0;

    for(int i=0;i<n;i++){
      cin >> v;
      wmax = max(wmax, v/w);
      data[v/w]++;
      datamax = max(datamax, data[v/w]);
    }

    double amount=0.01;
    for(int i=0;i<wmax+1;i++){
      amount += (double(wmax-i)/wmax)*(double(data[i])/datamax);
    }
    cout << amount << '\n';
  }
  return 0;
}
