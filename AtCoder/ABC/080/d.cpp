// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int imos[200005];
int time_[100005][30];

int main() {
    std::ios::sync_with_stdio(false);
    int n, C;cin >> n >> C;
    memset(imos, 0, sizeof(imos));
    memset(time_, 0, sizeof(time_));
    for(int i=0;i<n;i++){
        int s, t, c;cin >> s >> t >> c;c--;
        imos[s*2-1]++;
        imos[t*2]--;
        if(time_[s][c] == 1){
            imos[s*2-1]--;
            imos[s*2]++;
        }
        if(time_[t][c] == 1){
            imos[t*2-1]--;
            imos[t*2]++;
        }
        time_[s][c] = 1;
        time_[t][c] = 1;
    }
    int now = 0;
    int ans = 0;
    for(int i=0;i<200005;i++){
        now += imos[i];
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
