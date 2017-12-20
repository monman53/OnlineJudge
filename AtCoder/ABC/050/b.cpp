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
    int n;cin >> n;
    int sum = 0;
    vector<int> t(n);
    for(int i=0;i<n;i++){
        cin >> t[i];
        sum += t[i];
    }
    int m;cin >> m;
    for(int i=0;i<m;i++){
        int p, x;cin >> p >> x;p--;
        cout << sum+x-t[p] << endl;
    }
    return 0;
}
