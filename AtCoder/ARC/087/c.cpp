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
    int n;cin >> n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    map<int, int> m;
    for(int i=0;i<n;i++){
        m[b[i]]++;
    }
    int ans = 0;
    for(auto kv : m){
        int x = kv.first;
        int nx = kv.second;
        if(x > nx){
            ans += nx;
        }
        if(x < nx){
            ans += nx-x;
        }
    }
    cout << ans << endl;
    return 0;
}
