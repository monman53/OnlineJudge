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
    vector<int> a(1<<n);
    for(int i=0;i<1<<n;i++) cin >> a[i];
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<1<<i;j++){
            if(a[2*j] != a[2*j+1]){
                a[j] = abs(a[2*j]-a[2*j+1]);
            }else{
                a[j] = a[2*j];
            }
        }
    }
    cout << a[0];
    return 0;
}
