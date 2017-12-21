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
    string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
    int w;cin >> w;
    int n = s.size();
    for(int i=0;i<n;i+=w){
        cout << s.substr(i, min({n, w, n-i})) << endl;
    }
    return 0;
}
