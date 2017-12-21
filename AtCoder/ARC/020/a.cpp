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
    int a, b;cin >> a >> b;
    if(abs(a) < abs(b)){
        cout << "Ant" << endl;
    }else if(abs(a) > abs(b)){
        cout << "Bug" << endl;
    }else{
        cout << "Draw" << endl;
    }
    return 0;
}
