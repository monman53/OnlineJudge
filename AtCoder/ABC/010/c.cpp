// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

#define EPS (10e-9)

int main() {
    std::ios::sync_with_stdio(false);
    int txa, tya, txb, tyb, t, v;
    cin >> txa >> tya >> txb >> tyb >> t >> v;
    string ans = "NO";
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x, y;cin >> x >> y;
        int dxa = x-txa;
        int dya = y-tya;
        int dxb = x-txb;
        int dyb = y-tyb;
        if(sqrt(dxa*dxa+dya*dya)+sqrt(dxb*dxb+dyb*dyb) <= t*v+EPS){
            ans = "YES";
        }
    }
    cout << ans << endl;
    return 0;
}
