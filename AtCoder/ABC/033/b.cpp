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
    vector<string> s(n);
    vector<int> p(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> s[i] >> p[i];
        sum += p[i];
    }

    string ans = "atcoder";
    for(int i=0;i<n;i++){
        if(p[i] > sum/2) ans = s[i];
    }

    cout << ans << endl;
    return 0;
}
