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

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    double mmin = 10000;
    int ans = 0;
    for(int i=0;i<n;i++){
        double t, p;cin >> t >> p;
        if(p/t < mmin){
            mmin = p/t;
            ans = i+1;
        }
    }
    cout << ans << endl;
    return 0;
}
