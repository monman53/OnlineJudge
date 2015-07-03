#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll gcd(ll x, ll y){
  return y ? gcd(y, x%y) : x;
}

ull power(ull x, ull n, ull M = 1000000007){
  ull res = 1;
  if(n > 0){
    res = power(x, n/2, M);
    if(n%2 == 0){
      res = (res*res)%M;
    }else{
      res = (((res*res)%M)*x)%M;
    }
  }
  return res;
}

int main(){
  cout << power(4, 8) << endl;
  cout << power(4, 8, 1000) << endl;
  return 0;
}
