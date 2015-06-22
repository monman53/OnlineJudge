#include <iostream>
using namespace std;

int n;
int data[16][16];
int cost[16];
bool clear[16];

int main(){
  while(1){
    cin >> n;
    if(n == 0) break;
    
    for(int i=0;i<n;i++){
      clear[i] = false;
    }

    for(int i=0;i<n;i++){
      cin >> cost[i];
      for(int j=0;j<n;j++){
        cin >> data[i][j];
      }
    }
  }
  return 0;
}
