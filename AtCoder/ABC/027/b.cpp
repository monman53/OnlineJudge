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

int main() {
    int n;cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%n){
        cout << -1 << endl;
        return 0;
    }

    vector<int> as(n);
    as[0] = a[0];
    for(int i=1;i<n;i++){
        as[i] = as[i-1]+a[i];
    }

    int ans = 0;

    for(int i=0;i<n-1;i++){
        if(as[i] != (i+1)*(sum/n)){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
