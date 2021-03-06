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
    int a, b, r;cin >> a >> b >> r;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x, y;cin >> x >> y;
        int dx = x-a;
        int dy = y-b;
        if(dx*dx + dy*dy >= r*r){
            cout << "silent" << endl;
        }else{
            cout << "noisy" << endl;
        }
    }
    return 0;
}
