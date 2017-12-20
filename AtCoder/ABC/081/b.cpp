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
    int ans = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    while(true){
        bool flag = true;
        for(int i=0;i<n;i++){
            if(a[i]%2 == 1) flag = false;
        }
        if(flag){
            for(int i=0;i<n;i++){
                a[i] /= 2;
            }
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
