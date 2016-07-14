// gcd
//  ll gcd(ll x, ll, y)     x, yの最大公約数を返す
// depends on
typedef long long ll;
ll gcd(ll x, ll y){ // {{{
  return y ? gcd(y, x%y) : x;
}   // }}}
