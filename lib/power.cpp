// power_mod
//  power_mod(ull x, ull n, ull M = 1000000007) xのn乗をM(指定しない場合1000000007)で割ったあまりを高速で計算して返す
// depends on
typedef unsigned long long ull;
ull power_mod(ull x, ull n, ull M = 1000000007){ // {{{
  ull res = 1;
  if(n > 0){
    res = power_mod(x, n/2, M);
    if(n%2 == 0){
      res = (res*res)%M;
    }else{
      res = (((res*res)%M)*x)%M;
    }
  }
  return res;
} // }}}
