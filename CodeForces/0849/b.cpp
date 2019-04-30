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

bool online(LL i, LL j, LL yi, LL yj, LL x, LL y) {
    return (j-i)*y-(yj-yi)*x == (j-i)*yi-(yj-yi)*i;
}

int main() {
    LL n;cin >> n;
    vector<LL> y(n);
    for(LL i=0;i<n;i++){
        cin >> y[i];
    }
    bool ans = false;
    for(int k=0;k<2;k++){
        for(LL i=1;i<n;i++){
            bool tmp = true;
            vector<int> v;
            for(int j=1;j<n;j++){
                if(j == i) continue;
                if(!online(0, i, y[0], y[i], j, y[j])) v.push_back(j);
            }
            if(v.size() == 0) continue;
            if(v.size() == 1) tmp = true;
            if(v.size() > 1){
                for(int j=2;j<int(v.size());j++){
                    if(!online(v[0], v[1], y[v[0]], y[v[1]], v[j], y[v[j]])) tmp = false;
                }
                if((y[i]-y[0])*(v[1]-v[0]) != (y[v[1]]-y[v[0]])*(i-0)) tmp = false;
            }
            ans |= tmp;
        }
        reverse(y.begin(), y.end());
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
