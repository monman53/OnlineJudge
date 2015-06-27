#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
  int n;
  string s;
  map<string, int> data;
  int mmax = 0;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> s;
    if(data.find(s) == data.end()){
      data[s] = 1;
    }else{
      data[s]++;
    }
    mmax = max(mmax, data[s]);
  }

  cout << mmax << '\n';
}
