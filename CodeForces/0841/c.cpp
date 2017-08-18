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
    int m;cin >> m;
    vector<int> a(m);
    vector<PII> b(m);
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0;i<m;i++){
        ans[b[i].second] = a[i];
    }
    for(int i=0;i<m;i++){
        cout << ans[i];
        if(i != m-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
