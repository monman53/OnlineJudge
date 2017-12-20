// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int cnt[200000][26];

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    int n = s.size();
    memset(cnt, 0, sizeof(cnt));

    cnt[0][s[0]-'a'] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++){
            cnt[i][j] = cnt[i-1][j];
        }
        cnt[i][s[i]-'a']++;
    }

    LL ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(s[i]-'a' == j) continue;
            ans += cnt[n-1][j] - cnt[i][j];
        }
    }

    cout << ans+1 << endl;
    return 0;
}
