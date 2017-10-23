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
    string s;cin >> s;
    string t;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] != 'x'){
            t.push_back(s[i]);
        }
    }
    int m = t.size();
    for(int i=0;i<(m+1)/2;i++){
        if(t[i] != t[m-i-1]){
            cout << -1 << endl;
            return 0;
        }
    }

    int l = 0;
    int r = n-1;
    int ans = 0;
    while(l < r){
        if(s[l] == s[r]){
            l++;r--;
        }else if(s[l] == 'x'){
            l++;
            ans++;
        }else if(s[r] == 'x'){
            r--;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
