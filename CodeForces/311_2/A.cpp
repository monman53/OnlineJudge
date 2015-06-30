#include <iostream>
using namespace std;

int main(){
  int n;
  int min1, max1, min2, max2, min3, max3;
  cin >> n;
  cin >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
  int ans1, ans2, ans3;
  ans1 = ans2 = ans3 = 0;
  ans1 += min1;
  n -= min1;
  ans2 += min2;
  n -= min2;
  ans3 += min3;
  n -= min3;
//  cout << n << endl;
  while(ans1 < max1 && n > 0){
    ans1++;
    n--;
  }
  while(ans2 < max2 && n > 0){
    ans2++;
    n--;
  }
  while(ans3 < max3 && n > 0){
    ans3++;
    n--;
  }
//  cout << n << endl;
//  cout << n << endl;
  cout << ans1 << " " << ans2 << " " << ans3 << '\n';
  return 0;
}
