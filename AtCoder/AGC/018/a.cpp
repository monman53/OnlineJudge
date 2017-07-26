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

vector<LL> a;
map<LL, bool> m;
map<LL, bool> kita;

bool solve(LL n){
    if(kita.find(n) != kita.end()) return false;
    kita[n] = true;
    if(lower_bound(a.begin(), a.end(), n) != a.end()){
        if(m[n]) return true;
        LL next = *lower_bound(a.begin(), a.end(), n);
        return solve(next - n) || solve(n + next);
    }else{
        return false;
    }
}

int main() {
    LL n, k;cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]] = true;
    }
    sort(a.begin(), a.end());
    cout << (solve(k) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
