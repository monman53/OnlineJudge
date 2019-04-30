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
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> s(n);
    for(auto &ss : s) cin >> ss;
    int q;cin >> q;
    int ans = 0;
    for(int i=0;i<q;i++){
        int t;cin >> t;
        int l = 0;
        int r = n;
        while(l != r){
            int c = (l+r)/2;
            if(s[c] == t){
                ans++;
                break;
            }
            if(s[c] < t){
                l = c+1;
            }else{
                r = c;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
