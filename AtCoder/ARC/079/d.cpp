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
    LL k;cin >> k;
    cout << 50 << endl;
    if(k < 50LL){
        for(LL i=0;i<50LL;i++){
            cout << (i < k ? 50 : 0) << " ";
        }
        return 0;
    }
    for(LL i=0;i<50LL;i++){
        if(i < k%50LL){
            cout << (50LL+k/50LL) << " ";
        }else{
            cout << (50LL+k/50LL-1LL-i) << " ";
        }
    }
    return 0;
}
