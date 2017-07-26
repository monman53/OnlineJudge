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
    LL R, C, K;cin >> R >> C >> K;
    LL N;cin >> N;
    vector<LL> r(N), c(N);
    vector<LL> rs(R, 0), cs(C, 0);
    vector<LL> rh(N+1, 0), ch(N+1, 0);
    for(int i=0;i<N;i++){
        cin >> r[i] >> c[i];
        r[i]--;c[i]--;
        rs[r[i]]++;cs[c[i]]++;
    }
    for(int i=0;i<R;i++) rh[rs[i]]++;
    for(int i=0;i<C;i++) ch[cs[i]]++;
    
    LL ans = 0;

    for(int i=0;i<=K;i++){
        int j = K-i;
        ans += rh[i]*ch[j];
    }

    for(int i=0;i<N;i++){
        if(rs[r[i]]+cs[c[i]] == K)      ans--;
        if(rs[r[i]]+cs[c[i]] == K+1)    ans++;
    }

    printf("%lld\n", ans);

    return 0;
}
