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
    int n;cin >> n;
    vector<int> a(n);
    vector<int> count(100005, 0);
    for(auto &aa : a) cin >> aa;
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    int ans = 0;
    for(int i=0;i<=100000;i++){
        int sum = count[i]+count[i+1]+count[i+2];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
