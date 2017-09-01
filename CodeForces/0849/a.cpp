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

int n;
vector<int> a;

int main() {
    cin >> n;
    a.resize(n);
    for(auto &aa : a) cin >> aa;
    bool ans = (a[0]%2 == 1 && a[n-1]%2 == 1 && n%2 == 1);
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
