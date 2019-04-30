#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long int ll;
using namespace std;

ll m_n_x(ll m, ll n, ll x);
ll count(ll n);
string ntos(ll n);
ll find(ll f, ll t, ll s);
string fizzbuzz(ll from, ll to);

int main(){
  ll s;

  cin >> s;
  ll result = find(1, s, s);
  ll diff = count(result) - s;
  ll fizzbuzz_begin = max(result - 20LL, 1LL);
  string fb = fizzbuzz(fizzbuzz_begin, result + 20LL);

  cout << fb.substr(s - count(fizzbuzz_begin - 1) - 1, 20) << '\n';

  return 0;
}

ll m_n_x(ll m, ll n, ll x){
  return n/x - (m-1)/x;
}

ll count(ll n){
  ll ret=0;
  ll to;
  for(ll i=1,j=1;;i*=10,j++){
    if(n/(i*10) == 0){
      to = n;
      ret += (m_n_x(i, to, 15) - m_n_x(i, to, 3) - m_n_x(i, to, 5))*j;
      ret += (m_n_x(i, to, 3) + m_n_x(i, to, 5))*4;
      ret += (n-i+1)*j;
      break;
    }else{
      to = i*10-1;
      ret += (m_n_x(i, to, 15) - m_n_x(i, to, 3) - m_n_x(i, to, 5))*j;
      ret += (m_n_x(i, to, 3) + m_n_x(i, to, 5))*4;
      ret += (i*10-i)*j;
    }
  }
  return ret;
}

string ntos(ll n){
  string ret="";
  for(;n>0;n/=10){
    ret = char(ll('0') + n%10) + ret;
  }
  return ret;
}

ll find(ll f, ll t, ll s){
  ll k = (f+t)/2;
  ll c = count(k);
  if(abs(c-s) <= 8){
    return k;
  }else if(c-s > 0){
    find(f, k, s);
  }else{
    find(k, t, s);
  }
}

string fizzbuzz(ll from, ll to){
  string ret="";
  if(from == 0){
    return ret;
  }
  for(ll i=from;i<=to;i++){
    if(i%15 == 0){
      ret += "FizzBuzz";
    }else if(i%3 == 0){
      ret += "Fizz";
    }else if(i%5 == 0){
      ret += "Buzz";
    }else{
      ret += ntos(i);
    }
  }
  return ret;
}
