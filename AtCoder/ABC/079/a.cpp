// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    string ans = "No";
    int nn[4] = {n%10, n/10%10, n/100%10, n/1000%10};
    if(nn[0] == nn[1] && nn[1] == nn[2]) ans = "Yes";
    if(nn[1] == nn[2] && nn[2] == nn[3]) ans = "Yes";
    cout << ans << endl;
    return 0;
}
