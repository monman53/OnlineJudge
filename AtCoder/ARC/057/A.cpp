#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <climits>
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
    unsigned long long a, k, p;
    cin >> a >> k;
    if(k==0){
        cout << 2000000000000L - a << endl;
        return 0;
    }
    p = 1;
    for(ull n=1;;n++){
        p *= k+1;
        if((p-1)/k + p*a >= 2000000000000L){
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}
