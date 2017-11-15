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
    string s, t;cin >> s >> t;
    int n = s.size();
    int m = t.size();
    string ans = s;
    if(n < m){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    for(int i=n-m+1-1;i>=0;i--){
        bool flag = true;
        for(int j=0;j<m;j++){
            if(s[i+j] == '?' || s[i+j] == t[j]) continue;
            flag = false;
            break;
        }
        if(flag){
            for(int j=0;j<m;j++){
                ans[i+j] = t[j];
            }
            for(int j=0;j<n;j++){
                if(ans[j] == '?'){
                    ans[j] = 'a';
                }
            }
            cout << ans << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
    return 0;
}
