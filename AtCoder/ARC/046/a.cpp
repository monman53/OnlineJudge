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
    vector<string> ans;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=9;j++){
            string s = "";
            for(int k=0;k<i;k++){
                s.push_back('0'+j);
            }
            ans.push_back(s);
        }
    }
    cout << ans[n-1] << endl;
    return 0;
}
