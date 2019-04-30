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
    int a, b, f, k;cin >> a >> b >> f >> k;

    vector<int> v;
    for(int i=0;i<k;i++){
        bool last = (i == k-1);
        bool dir  = (i%2 == 0);
        v.push_back(last?(dir?a-f:f):(dir?(a-f)*2:f*2));
    }

    int n = v.size();
    int ans = 0;
    int now = b-f;
    if(now < 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(now < v[i]){
            now = b;
            ans++;
        }
        now -= v[i];
        if(now < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}
