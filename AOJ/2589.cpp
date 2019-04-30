#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

ll gcd(ll m, ll n){
  if(n == 0) return m;
  return gcd(n, m%n);
}

class Bunsu{
  public:
  ll n, d;
  Bunsu(ll i, ll j){
    n = i;
    d = j;
    yakubun();
  }
  void yakubun(){
    ll gcd_ = gcd(abs(n), abs(d));
    n /= gcd_;
    d /= gcd_;
  }
  void show(){
    if(n == 0){
      cout << 0;
    }else if(d == 1){
      cout << n;
    }else{
      cout << n << "/" << d;
    }
    cout << '\n';
  }
};


Bunsu add(Bunsu v1, Bunsu v2){
  return Bunsu(v1.n*v2.d + v2.n*v1.d, v1.d*v2.d);
}

int power(int n){
  int ret=1;
  for(int i=0,ret=1;i<n;i++){
    ret *= 2;
  }
  return ret;
}

int main(){
  string s;
  while(1){
    cin >> s;
    if(s == "#") break;
    int num=0;
    int data[20];
    Bunsu ans(0,1);
    for(int i=0;i<s.size();){
      if(s[i] == 'n'){
        data[num] = 1;
        num++;
        i += 5;
        continue;
      }
      if(s[i] == 'w'){
        data[num] = 0;
        num++;
        i += 4;
        continue;
      }
    }
    if(data[num-1]){
      ans = Bunsu(0,1);
    }else{
      ans = Bunsu(90,1);
    }
//    cout << "num=" << num << endl;
    for(long long int i=num-2,n=2;i>=0;i--,n*=2){
      if(data[i]){
        ans = add(ans, Bunsu(-90, n));
      }else{
        ans = add(ans, Bunsu(90, n));
      }
    }
    ans.show();
  }
  return 0;
}
