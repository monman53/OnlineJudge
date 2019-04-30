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
    int k, t;cin >> k >> t;
    vector<int> a(t);
    int ssum = 0;
    int mmax = 0;
    for(int i=0;i<t;i++){
        cin >> a[i];
        mmax = max(mmax, a[i]);
        ssum += a[i];
    }
    cout << max(0, mmax-(ssum-mmax)-1) << endl;
    return 0;
}
