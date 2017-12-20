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
    int n, m;cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    for(int i=0;i<m;i++) cin >> c[i] >> d[i];

    for(int i=0;i<n;i++){
        int md = INF;
        int mi = -1;
        for(int j=0;j<m;j++){
            int dd = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(dd < md){
                md = dd;
                mi = j;
            }
        }
        cout << mi+1 << endl;
    }
    return 0;
}
