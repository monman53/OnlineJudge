#include <iostream>
using namespace std;

int main(){
  int n, a, b;

  string s;
  int d;
  int x = 0;
  int dir;

  cin >> n >> a >> b;

  for(int i=0;i<n;i++){
    cin >> s >> d;
    if(s[0] == 'E'){
      dir = 1;
    }else{
      dir = -1;
    }

    if(d < a){
      x += dir*a;
    }else if(d > b){
      x += dir*b;
    }else{
      x += dir*d;
    }
  }

  if(x == 0){
    cout << 0 << '\n';
  }else if(x > 0){
    cout << "East " << x << '\n';
  }else{
    cout << "West " << -x << '\n';
  }

  return 0;
}
