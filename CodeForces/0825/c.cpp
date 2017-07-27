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
    int n, k;cin >> n >> k;
    vector<int> a(n);
    for(auto &aa : a) cin >> aa;
    vector<int> v;
    v.push_back(k);
    int bb = k;
    for(int i=0;i<n;i++){
        if(a[i] > bb*2){
            v.push_back(a[i]);
            bb = a[i];
        }
    }
    int ans = 0;
    for(int i=0;i<int(v.size())-1;i++){
        if(v[i]*2 < v[i+1]) ans = 1;
    }
    cout << ans << endl;
    return 0;
}
