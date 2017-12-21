// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int L, R;cin >> L >> R;
    vector<int> l(L), r(R);
    for(int i=0;i<L;i++) cin >> l[i];
    for(int i=0;i<R;i++) cin >> r[i];
    int ans = 0;
    for(int i=0;i<L;i++){
        for(int j=0;j<R;j++){
            if(l[i] == r[j]){
                ans++;
                r[j] = 0;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
