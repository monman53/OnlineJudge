#include <iostream>
#include <algorithm>
using namespace std;

int n;
int data[16][16];
int cost[16];
bool clear[16];
int mmin;

void ans(int sum, int count){
  int nowcost;
  int buf[16];

  if(sum > mmin) return;

  if(count == n){
    mmin = min(mmin, sum);
  }

  for(int i=0;i<n;i++){
    if(!clear[i]){
      clear[i] = true;
      nowcost = cost[i];
      for(int j=0;j<n;j++){
        buf[j] = cost[j];
        cost[j] = min(cost[j], data[i][j]);
      }
      ans(sum + nowcost, count+1);
      for(int j=0;j<n;j++){
        cost[j] = buf[j];
      }
      clear[i] = false;
    }
  }
}

int main(){
  while(1){
    cin >> n;
    if(n == 0) break;
    mmin = 99999999;
    
    for(int i=0;i<n;i++){
      clear[i] = false;
    }

    for(int i=0;i<n;i++){
      cin >> cost[i];
      for(int j=0;j<n;j++){
        cin >> data[j][i];
      }
    }
    ans(0, 0);
    cout << mmin << '\n';
  }
  return 0;
}
