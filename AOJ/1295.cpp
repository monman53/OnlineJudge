#include <iostream>
#include <map>
using namespace std;

int main(){
  int w, d;
  while(1){
    cin >> w >> d;
    if(w==0) break;
    
    int h;
    map<int, int> data;

    int count = 0;
    for(int i=0;i<w;i++){
      cin >> h;
      count += h;
      if(data.find(h) == data.end()){
        data[h] = 1;
      }else{
        data[h] = data[h] + 1;
      }
    }
    for(int i=0;i<d;i++){
      cin >> h;
      if(data.find(h) == data.end()){
        count += h;
      }else{
        if(data[h] == 0){
          count += h;
        }else{
          data[h] = data[h] - 1;
        }
      }
    }
    cout << count << '\n';
  }
  return 0;
}
