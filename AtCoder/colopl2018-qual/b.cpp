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
    int n, x;cin >> n >> x;
    string s;cin >> s;
    vector<int> t(n);
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            ans += t[i];
        }else{
            ans += min(t[i], x);
        }
    }
    cout << ans << endl;
    return 0;
}
