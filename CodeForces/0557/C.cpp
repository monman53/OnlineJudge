#include <iostream>
#include <cstdio>
using namespace std;

struct Data{
  int count;
  int cost;
};

int main(){
  int n;
  scanf("%d", &n);
  int data[n];
  Data legs[100001];
  for(int i=0;i<100001;i++){
    legs[i].count = 0;
    legs[i].cost = 0;
  }
  for(int i=0;i<n;i++){
    scanf("%d", &data[i]);
    legs[data[i]].count++;
  }
  int d;
  for(int i=0;i<n;i++){
    scanf("%d", &d);
    legs[data[i]].cost += d;
  }
  int i=100000;
  int ans=0;
  while(1){
    if(i == 1) break;
    if(legs[i].count == 0){
      i--;
      continue;
    }
    if(legs[i].count > n/2) break;
    ans += (legs+i)->cost;
    i--;

    cout << i << endl;
  }
  printf("%d\n", ans);
  return 0;
}
