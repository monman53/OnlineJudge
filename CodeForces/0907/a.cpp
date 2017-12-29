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
    int V1, V2, V3, Vm;cin >> V1 >> V2 >> V3 >> Vm;
    if(2*Vm >= V3 && 2*Vm < 2*V2){
        if(Vm <= 2*V3){
            cout << V1*2 << endl;
            cout << V2*2 << endl;
            cout << min(2*Vm, V3*2) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
