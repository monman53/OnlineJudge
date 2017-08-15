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
    int n, k;cin >> n >> k;
    int sum = 0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        sum += a;
        if(sum >= 8){
            if(k <= 8){
                cout << i+1 << endl;
                return 0;
            }
            sum -= 8;
            k -= 8;
        }else{
            if(k <= sum){
                cout << i+1 << endl;
                return 0;
            }
            k -= sum;
            sum = 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
