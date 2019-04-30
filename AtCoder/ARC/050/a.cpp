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
    char C, c;cin >> C >> c;
    if(C-'A' == c-'a'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
