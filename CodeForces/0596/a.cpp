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
    int x[4];
    int y[4];
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    if(n == 1) cout << -1 << endl;
    if(n > 2) cout << max(abs(x[0]-x[1]), abs(x[0]-x[2]))*max(abs(y[0]-y[1]), abs(y[0]-y[2])) << endl;
    if(n == 2){
        if(x[0] != x[1] && y[0] != y[1]){
            cout << abs(x[0]-x[1])*abs(y[0]-y[1]) << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
