#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  bool furui[1000];
  vector<int> list;
  for(int i=0;i<1000;i++){
    furui[i] = true;
  }
  for(int i=2;i<1000;i++){
    if(furui[i]){
      for(int j=2;i*j<1000;j++){
        furui[i*j] = false;
      }
      list.push_back(i);
    }
  }
  int m, a, b;
  while(1){
    cin >> m >> a >> b;
    if(m == 0) break;
    bool flag = true;
    int p, q;
    int maxpq=0;
    for(int i=0;list[i]*list[i]<=m;i++){
      for(int j=i;list[i]*list[j]<=m && double(list[i])/double(list[j]) >= double(a)/double(b);j++){
        if(maxpq <= list[i]*list[j]){
          maxpq = list[i]*list[j];
          p = i;
          q = j;
        }
      }
    }
    cout << list[p] << " " << list[q] << '\n';
  }

}
