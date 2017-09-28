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
    int n, k;cin >> n >> k;
    map<char, int> m;
    for(int i=0;i<n;i++){
        string p;cin >> p;
        m[p[0]]++;
    }
    priority_queue<int> pq;
    for(auto kv : m) pq.push(kv.second);
    int ans = 0;
    bool flag = true;
    while(flag){
        vector<int> v;
        for(int i=0;i<k;i++){
            if(pq.empty()){
                flag = false;
                break;
            }
            int vv = pq.top();
            pq.pop();
            if(--vv == 0) continue;
            v.push_back(vv);
        }
        if(!flag) break;
        ans++;
        for(auto vv : v) pq.push(vv);
    }
    cout << ans << endl;
    return 0;
}
