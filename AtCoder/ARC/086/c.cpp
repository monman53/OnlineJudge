// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    map<int, int> m;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        m[a]--;
    }
    for(auto kv : m){
        pq.push(kv.second);
    }
    int ans = 0;
    while(pq.size() > k){
        ans -= pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}
