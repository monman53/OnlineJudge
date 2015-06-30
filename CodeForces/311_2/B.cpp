#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct comp{
  bool operator()(double x, double y) const {
    return x > y;
  }
};

typedef long long int ll;

int main(){
  int n, w; 
  scanf("%d %d", &n, &w);
  priority_queue<double, vector<double>, comp> data;
  //double data[2*n];
  double a;
  for(int i=0;i<2*n;i++){
    scanf("%lf", &a);
    data.push(a);
    //cin >> data[i];
  }
  //sort(data, data+2*n);
  //double girlmin = data[0];
  //double manmin = data[n];
  double girlmin = data.top();
  for(int i=0;i<n;i++){
    data.pop();
  }
  double manmin = data.top();
  /*
  double manmin = 2000000000;
  for(int i=0;i<n;i++){
    a = data.top();
    data.pop();
    manmin = min(manmin, a);
  }*/

  if(girlmin*2 > manmin){
    girlmin = manmin/2;
  }else if(manmin > girlmin/2){
    manmin = girlmin*2;
  }
  if(manmin*n+girlmin*n > w){
    cout << w << '\n';
  }else{
    cout << (manmin*n + girlmin*n) << '\n';
  }

  return 0;
}
