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
    for(auto &c : s){
        if('A' <= c && c <= 'Z'){
            c = c-'A'+'a';
        }
    }

    int n = s.size();
    int l, r;
    for(l=0;l<n;l++){
        if(s[l] == 'i') break;
    }
    for(r=n-1;r>=0;r--){
        if(s[r] == 't') break;
    }

    string ans = "NO";
    for(int i=l;i<=r;i++){
        if(s[i] == 'c') ans = "YES";
    }

    cout << ans << endl;
    return 0;
}
