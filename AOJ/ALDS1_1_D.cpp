#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int mmin, mmax=-1000000000;
  int n;
  int r;
  cin >> n;

  cin >> mmin;

  for(int i=0;i<n-1;i++){
    cin >> r;
    mmax = max(mmax, r - mmin);
    mmin = min(mmin, r);
  }

  cout << mmax << '\n';

  return 0;
}
