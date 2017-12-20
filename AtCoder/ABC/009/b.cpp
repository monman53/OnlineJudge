// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        s.insert(a);
    }
    vector<int> v;
    for(auto a : s){
        v.push_back(-a);
    }
    sort(v.begin(), v.end());
    cout << -v[1] << endl;
    return 0;
}
