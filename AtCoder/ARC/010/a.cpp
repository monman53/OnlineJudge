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
    int n, m, a, b;cin >> n >> m >> a >> b;
    vector<int> c(m);
    for(int i=0;i<m;i++) cin >> c[i];
    for(int i=0;i<m;i++){
        if(n <= a) n += b;
        if(c[i] > n){
            cout << i+1 << endl;
            return 0;
        }
        n -= c[i];
    }
    cout << "complete" << endl;
    return 0;
}
