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
    map<char, char> m;
    for(char i='0';i<='9';i++){
        char b;cin >> b;
        m[b] = i;
    }
    int n;cin >> n;
    vector<pair<int, string>> ans(n);
    for(int i=0;i<n;i++){
        string a;cin >> a;
        string s = a;
        for(auto &c : s){
            c = m[c];
        }
        ans[i] = {stoi(s), a};
    }
    sort(ans.begin(), ans.end());
    for(auto a : ans){
        cout << a.second << endl;
    }
    return 0;
}
