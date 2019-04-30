#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m, a, b, c, t;

  while(1){
    cin >> n >> m >> a >> b >> c >> t;
    if(n == 0) break;

    vector<int> cell(n+2, 0);
    vector<int> buf(n+2, 0);
    vector<vector<int> > data;

    for(int i=1;i<=n;i++){
      cin >> cell[i];
    }
    data.push_back(cell);

    for(int i=0;i<t;i++){
      for(int j=1;j<=n;j++){
        buf[j] = (a*cell[j-1] + b*cell[j] + c*cell[j+1])%m;
      }
      for(int j=0;j<n+2;j++){
        cell[j] = buf[j];
      }
      cout << data.size() << endl;
      for(int j=0;j<(int)data.size();j++){
        if(cell == data[j]){
          break;
        }
      }
      data.push_back(cell);
    }

    for(int i=1;i<=n;i++){
      cout << cell[i];
      if(i != n){
        cout << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
