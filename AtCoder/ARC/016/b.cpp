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
    vector<string> x;
    x.push_back(".........");
    for(int i=0;i<n;i++){
        string xx;cin >> xx;
        x.push_back(xx);
    }
    x.push_back(".........");
    n += 2;
    int ans = 0;
    for(int j=0;j<9;j++){
        for(int i=1;i<n;i++){
            char c = x[i][j];
            char bc = x[i-1][j];
            if(c == 'x') ans++;
            if(bc == 'o' && c != 'o') ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
