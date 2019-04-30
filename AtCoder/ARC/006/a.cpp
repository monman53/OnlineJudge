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
    bitset<10> e, l;
    for(int i=0;i<6;i++){
        int ee;cin >> ee;
        e[ee] = 1;
    }
    int b;cin >> b;
    for(int i=0;i<6;i++){
        int ll;cin >> ll;
        l[ll] = 1;
    }
    bitset<10> ans = e&l;
    int n = ans.count();
    if(n == 6){
        cout << 1 << endl;
    }
    if(n == 5){
        bitset<10> a = e^l;
        if(a[b] == 1){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
    }
    if(n == 4) cout << 4 << endl;
    if(n == 3) cout << 5 << endl;
    if(n == 2) cout << 0 << endl;
    if(n == 1) cout << 0 << endl;
    if(n == 0) cout << 0 << endl;
    return 0;
}
