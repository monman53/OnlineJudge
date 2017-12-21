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
    int n;cin >> n;
    if(n == 1){
        cout << "NO" << endl;
        return 0;
    }
    if(n == 2){
        cout << "YES" << endl;
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
