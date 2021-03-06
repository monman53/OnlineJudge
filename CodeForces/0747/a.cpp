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
    int ansa = 1;
    int ansb = n;
    int ans = INT_MAX;
    for(int a=1;a*a<=n;a++){
        if(n%a == 0){
            int b = n/a;
            if(b-a < ans){
                ans = b-a;
                ansa = a;
                ansb = b;
            }
        }
    }
    cout << ansa << " " << ansb << endl;
    return 0;
}
