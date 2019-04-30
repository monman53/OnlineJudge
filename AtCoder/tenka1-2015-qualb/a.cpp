// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    vector<LL> a(20);
    a[0] = 100;
    a[1] = 100;
    a[2] = 200;
    for(int i=3;i<20;i++){
        a[i] = a[i-1]+a[i-2]+a[i-3];
    }
    cout << a[19] << endl;
    return 0;
}
