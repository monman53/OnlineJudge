// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

LL sum(LL n) {
    LL ret = 0;
    while(n > 0){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    LL n;cin >> n;
    vector<LL> ans;
    for(LL i=max(1LL, n-10000);i<=n;i++){
        if(i+sum(i)==n){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto m : ans){
        cout << m << endl;
    }
    return 0;
}
