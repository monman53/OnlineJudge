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
    int n, m;cin >> n >> m;
    string s;cin >> s;
    for(int i=0;i<m;i++){
        int l, r;cin >> l >> r;l--;
        char c1, c2;cin >> c1 >> c2;
        for(int j=l;j<r;j++){
            if(s[j] == c1) s[j] = c2;
        }
    }
    cout << s << endl;
    return 0;
}
