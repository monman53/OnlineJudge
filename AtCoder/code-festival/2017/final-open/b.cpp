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
    int n = s.size();
    map<char, int> cnt;
    for(auto c : s) cnt[c]++;
    string ans = "YES";
    for(auto kv : cnt){
        if(kv.second > (n+2)/3) ans = "NO";
    }
    cout << ans << endl;
    return 0;
}
