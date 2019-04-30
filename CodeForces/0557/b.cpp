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
    int n;double w;cin >> n >> w;
    vector<int> a(2*n);
    for(auto &aa : a) cin >> aa;
    sort(a.begin(), a.end());
    double girl = a[0];
    double boy = a[n];
    if(girl*2.0 > boy){
        girl = boy/2;
    }
    girl = min(girl, w/(3.0*n));
    printf("%lf\n", girl*n*3.0);
    return 0;
}
