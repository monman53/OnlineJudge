// header {{{
// #define NDEBUG
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
    LL L, R, x, y, k;
    cin >> L >> R >> x >> y >> k;
    LL l = x;
    LL r = y+1;
    while(l != r){
        LL c = (l+r)/2;
        if(L <= c*k && c*k <= R){
            cout << "YES" << endl;
            return 0;
        }
        if(c*k < L){
            l = c+1;
        }else{
            r = c;
        }
    }
    cout << "NO" << endl;
    return 0;
}
