#include <iostream>
using namespace std;
typedef long long int ll;

int main(){
  ll n, ans=0;
  cin >> n;
  for(ll i=1;i<n;i*=3){
    ans++;
  }
  cout << ans << endl;
  return 0;
}
