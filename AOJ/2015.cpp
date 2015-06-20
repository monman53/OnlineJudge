#include <iostream>
#include <map>
using namespace std;

int main(){
  int n, m;
  while(1){
    cin >> n >> m;
    if(n == 0) break;

    int hs[1501];
    int ws[1501];
    hs[0] = 0;
    ws[0] = 0;
    int x;
    map<int, int> data;
    int count = 0;

    for(int i=1;i<=n;i++){
      cin >> x;
      hs[i] = hs[i-1] + x; 
      for(int j=0;j<i;j++){
        if(data.find(hs[i] - hs[j]) == data.end()){
          data[hs[i] - hs[j]] = 1;
        }else{
          data[hs[i] - hs[j]]++;
        }
      }
    }
    for(int i=1;i<=m;i++){
      cin >> x;
      ws[i] = ws[i-1] + x;
      for(int j=0;j<i;j++){
        if(data.find(ws[i]-ws[j]) != data.end()){
          count += data[ws[i]-ws[j]];
        }
      }
    }
    cout << count << '\n';
  }
  return 0;
}
