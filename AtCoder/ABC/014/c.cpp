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
    int imos[1000005];
    memset(imos, 0, sizeof(imos));
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int a, b;cin >> a >> b;
        imos[a]++;
        imos[b+1]--;
    }
    int now = 0;
    int ans = 0;
    for(int i=0;i<1000005;i++){
        now += imos[i];
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
