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
    int n, x;cin >> n >> x;
    vector<int> a(n);
    for(auto &aa : a) cin >> aa;
    int ans = 0;
    bitset<20> bit(x);
    for(int i=0;i<n;i++){
        if(bit[i]){
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
