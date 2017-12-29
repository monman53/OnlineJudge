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
    for(int i=0;i<n;i++){
        string p, q, r;cin >> p >> q >> r;
        int n = r.size();
        if(p == "BEGINNING") cout << r[0];
        if(p == "MIDDLE") cout << r[n/2];
        if(p == "END") cout << r[n-1];
    }
    cout << endl;
    return 0;
}
