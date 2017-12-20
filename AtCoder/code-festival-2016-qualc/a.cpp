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
    int l;
    for(l=0;l<n;l++){
        if(s[l] == 'C') break;
    }
    int r;
    for(r=n-1;r>=0;r--){
        if(s[r] == 'F') break;
    }

    cout << (l<r ? "Yes" : "No") << endl;

    return 0;
}
