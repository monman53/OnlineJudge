// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

// 文字列の分解
// ABC033
vector<string> split(string &s, char c) {
    vector<string> ret;
    int b = 0;
    int n = s.size();
    int i;
    for(i=0;i<n;i++){
        if(s[i] == c){
            ret.push_back(s.substr(b, i-b));
            b = i+1;
        }
    }
    ret.push_back(s.substr(b, i-b));
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    auto ss = split(s, '+');
    int ans = 0;
    for(auto s : ss){
        ans++;
        for(auto c : s){
            if(c == '0'){
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
