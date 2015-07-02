#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){
  ll n;
  int m, d;
  cin >> n >> m >> d;
  vector<ll> a(m);
  vector<ll> r();
  
  // input
  for(int i=0;i<m;i++){
    cin >> a[i];
  }

  ll ans = n;
  ll dif = 1;
  for(int i=0;i<d;i++){
    for(int j=0;j<m;j++){
      cin >> r[i][j];
    }
  }

  return 0;
}
