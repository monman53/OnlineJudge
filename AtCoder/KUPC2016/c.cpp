// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t-- > 0){
        int n, d;cin >> n >> d;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(d);
        for(int i=0;i<n-1;i++){
            int x = pq.top();
            pq.pop();
            pq.push(127);
            pq.push(127^x);
        }
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
