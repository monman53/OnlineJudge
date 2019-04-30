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
    vector<LL> a(n);
    map<int, int> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int count = 0;
    LL ans = 1;
    for(int i=0;i<n;i++){
        if(m[a[i]] > 1){
            ans *= a[i];
            count++;
            m[a[i]]-=2;
            if(count == 2) break;
        }
    }
    if(count != 2) ans = 0;
    printf("%lld\n", ans);
    return 0;
}
