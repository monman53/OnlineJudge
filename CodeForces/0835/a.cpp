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
    int s;cin >> s;
    int v1, v2, t1, t2;cin >> v1 >> v2 >> t1 >> t2;
    int ans1 = v1*s + 2*t1;
    int ans2 = v2*s + 2*t2;
    if(ans1 < ans2){
        cout << "First" << endl;
    }else if(ans1 > ans2){
        cout << "Second" << endl;
    }else{
        cout << "Friendship" << endl;
    }
    return 0;
}
