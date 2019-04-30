#include <iostream>
#include <vector>
#define MAX 300000
using namespace std;


int main(){
  int hurui[MAX];
  vector<int> list;
  for(int i=0;i<MAX;i++){
    hurui[i] = -1;
  }
  for(int i=6;i<MAX;){
    if(hurui[i]!=0){
      for(int j=2;j*i<MAX;j++){
        hurui[i*j] = 0;
      }
      list.push_back(i);
    }
    if(i%7 == 6){
      i += 2;
    }else{
      i += 5;
    }
  }
  int n;
  while(1){
    cin >> n;
    if(n == 1) break;
    cout << n << ":";
    for(int i=0;i<list.size();i++){
      if(n%list[i] == 0){
        cout << " " << list[i];
      }
    }
    cout << '\n';
  }
  return 0;
}
