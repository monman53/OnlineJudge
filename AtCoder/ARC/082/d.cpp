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
    vector<int> p(n);
    for(auto &pp : p){
        cin >> pp;
        pp--;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(p[i] == i){
            ans++;
        }
    }
    for(int i=0;i<n-1;){
        if(p[i] == i && p[i+1] == i+1){
            ans--;
            i+=2;
        }else{
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
