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
    LL n, k, m;cin >> n >> k >> m;
    vector<LL> t(k);
    for(auto &tt : t) cin >> tt;
    LL sum = 0;for(auto tt : t) sum += tt;

    LL ans = m/sum*(k+1);

    LL count = 0;
    LL nokori = m%sum;
    for(auto tt : t){
        if(tt <= nokori){
            count++;
            nokori-=tt;
        }
    }
    ans += count;

    printf("%lld\n", ans);

    return 0;
}
