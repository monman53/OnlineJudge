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
#define CILING(a, b)    (((a)+(b)-1)/(b))

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
    LL N;cin >> N;
    LL t = 0LL;
    LL now = 1LL;
    LL depth = 1;
    for(LL n=N;n>0LL;n/=2LL) depth = 1LL-depth;
    while(true){
        if(depth){
            now = now*2LL + t;
        }else{
            now = now*2LL + (1LL-t);
        }
        if(now > N){
            cout << (1LL-t ? "Aoki" : "Takahashi") << endl;
            break;
        }
        t = 1LL-t;
    }
    return 0;
}
