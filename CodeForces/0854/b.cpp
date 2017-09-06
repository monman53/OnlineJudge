// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, k;cin >> n >> k;
    if(n == k || k == 0){
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    LL mmin = 1;
    LL mmax = 0;
    if(k*3 >= n){
        mmax = n-k;
    }else{
        mmax = 2*k;
    }
    cout << mmin << " " << mmax << endl;
    return 0;
}
