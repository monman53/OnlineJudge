// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
// #include <tuple>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

// template<class T>
// using P = pair<T, T>;
using ll  = long long;
using ull = unsigned long long;
// }}}

int main() {
    int k, n;cin >> k >> n;
    vector<ll> a(k);for(auto &aa : a) cin >> aa;
    vector<ll> b(n);for(auto &bb : b) cin >> bb;
    vector<ll> aa(k);
    
    aa[0] = a[0];
    for(int i=1;i<k;i++){
        aa[i] = aa[i-1]+a[i];
    }

    // if(n == 1){
    //     set<ll> st;
    //     for(auto aaa : aa) st.insert(aaa);
    //     cout << st.size() << endl;
    //     return 0;
    // }

    // ll aamin = *min_element(aa.begin(), aa.end());
    
    set<ll> aa2;
    for(auto aaa : aa) aa2.insert(aaa);

    // sort(b.begin(), b.end());
    set<ll> bb2;
    for(auto bb : b) bb2.insert(bb);

    int ans = 0;

    for(auto aa2_ : aa2){
        ll ini = b[0] - aa2_;
        set<ll> s;
        for(auto aa2__ : aa2){
            s.insert(ini + aa2__);
        }
        // for(auto vv : v) cout << vv << endl;
        // cout << endl;
        // sort(v.begin(), v.end());

        set<ll> result;

        set_symmetric_difference(bb2.begin(), bb2.end(),
                                 s.begin(), s.end(),
                                 inserter(result, result.end()));
        if(result.size() == s.size() - b.size()){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
