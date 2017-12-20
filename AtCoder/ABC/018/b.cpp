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
    string s;cin >> s;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int l, r;cin >> l >> r;l--;
        reverse(&s[l], &s[r]);
    }
    cout << s << endl;
    return 0;
}
