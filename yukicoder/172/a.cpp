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
    vector<string> s(n), t(n);
    for(auto &ss : s) cin >> ss;
    for(auto &tt : t) cin >> tt;
    for(int i=0;i<n;i++){
        if(s[i] != t[i]){
            cout << i+1 << endl;
            cout << s[i] << endl;
            cout << t[i] << endl;
            break;
        }
    }
    return 0;
}
