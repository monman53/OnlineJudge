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
    int n;cin >> n;
    vector<int> imos(100005, 0);
    for(int i=0;i<n;i++){
        int a, b;cin >> a >> b;
        imos[a]++;
        imos[b+1]--;
    }
    int ans = 0;
    int now = 0;
    for(int i=0;i<100005;i++){
        now += imos[i];
        if(i <= now+1){
            ans = max(ans, i-1);
        }
    }
    cout << ans << endl;
    return 0;
}
