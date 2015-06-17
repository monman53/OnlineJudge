#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, k, m;
  while(1){
    vector<int> data;
    vector<int> rmlist;
    cin >> n >> k >> m;
    if(n == 0) break;

    for(int i=0;i<n;i++){
      data.push_back(i+1);
    }
    int pos = m-1;
    int size = n;

    while(size != 1){
      data.erase(find(data.begin(), data.end(), data[pos]));
      pos = (pos-1+k)%--size;
    }
    cout << data[0] << '\n';
  }
  return 0;
}
