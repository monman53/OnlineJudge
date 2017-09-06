// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)

using LL  = long long;
using P   = pair<LL, LL>;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    LL n, k;cin >> n >> k;
    priority_queue<P> pq;
    LL sum = 0;
    vector<LL> v(n);
    for(LL i=0;i<n+k;i++){
        if(i<n){
            LL c;cin >> c;
            pq.push({c, i});
        }
        if(k<=i){
            auto p = pq.top();pq.pop();
            sum += (i-p.second)*p.first;
            v[p.second] = i+1;
        }
    }
    cout << sum << endl;
    for(auto vv : v) cout << vv << endl;
    return 0;
}
