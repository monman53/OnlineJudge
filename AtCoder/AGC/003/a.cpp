// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
// #define EQ(a, b)    (abs((a)-(b)) < EPS)
inline bool EQ(double a, double b) {return abs(a-b) < EPS;}
// ciling(x/y) = (x+y-1)/y

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
    string s;cin >> s;
    map<char, bool> m;
    m['N'] = false;
    m['W'] = false;
    m['S'] = false;
    m['E'] = false;
    for(auto c : s) m[c] = true;
    cout << ((m['N'] ^ m['S']) | (m['W'] ^ m['E']) ? "No" : "Yes") << endl;
    return 0;
}
