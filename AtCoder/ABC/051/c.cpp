// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

void print(char c, int n){
    for(int i=0;i<n;i++){
        cout << c;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx-sx;
    int dy = ty-sy;
    print('U', dy);print('R', dx);
    print('D', dy);print('L', dx);
    print('L', 1);print('U', dy+1);print('R', dx+1);print('D', 1);
    print('R', 1);print('D', dy+1);print('L', dx+1);print('U', 1);
    cout << endl;
    return 0;
}
