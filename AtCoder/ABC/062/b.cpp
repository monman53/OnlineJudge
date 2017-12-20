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
    int h, w;cin >> h >> w;
    for(int i=0;i<w+2;i++) cout << '#';
    cout << endl;
    for(int i=0;i<h;i++){
        string s;cin >> s;
        cout << '#' << s << '#' << endl;
    }
    for(int i=0;i<w+2;i++) cout << '#';
    cout << endl;
    return 0;
}
