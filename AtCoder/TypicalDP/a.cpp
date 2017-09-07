// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    set<int> dp;
    dp.insert(0);
    for(int i=0;i<n;i++){
        int p;cin >> p;
        auto tmp = dp;
        for(auto pp : tmp){
            dp.insert(pp+p);
        }
    }
    cout << dp.size() << endl;
    return 0;
}
