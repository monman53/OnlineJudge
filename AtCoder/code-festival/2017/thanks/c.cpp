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
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    vector<LL> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        pq.push({a[i], i});
    }
    LL ans = 0;
    for(int i=0;i<k;i++){
        auto c = pq.top();
        pq.pop();
        ans += c.first;
        //cout << c.second << " " << c.first << endl;
        pq.push({c.first+b[c.second], c.second});
    }
    cout << ans << endl;
    return 0;
}
