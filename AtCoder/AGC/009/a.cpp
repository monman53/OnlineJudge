// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

// 最小公倍数
LL lcm(LL m, LL n) {
    return m/gcd(m, n)*n;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<LL> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    LL x = 0;
    for(int i=n-1;i>=0;i--){
        a[i] += x;
        if(a[i]%b[i] == 0) continue;
        if(a[i] <= b[i]){
            x += b[i]-a[i];
        }else{
            x += (a[i]+b[i]-1)/b[i]*b[i]-a[i];
        }
    }
    cout << x << endl;
    return 0;
}
