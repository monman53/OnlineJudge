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
    char c;cin >> c;
    switch(c){
        case 'O':
        case 'P':
        case 'K':
        case 'L':
            cout << "Right" << endl;
            break;
        default:
            cout << "Left" << endl;
            break;
    }
    return 0;
}
