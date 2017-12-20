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
    int l, r;
    for(int i=0;i<n;i++){
        if(s[i] == 'A'){
            l = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i] == 'Z'){
            r = i;
            break;
        }
    }

    cout << r-l+1 << endl;
    return 0;
}
