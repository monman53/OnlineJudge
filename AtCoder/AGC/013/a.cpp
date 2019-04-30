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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(n < 3){
        cout << 1 << endl;
        return 0;
    }
    int ans = 1;
    int d = 0;
    for(int i=0;i<n-1;i++){
        if(a[i] == a[i+1]) continue;
        if(d == 0){
            if(a[i] > a[i+1]){
                d = -1;
            }else{
                d = 1;
            }
        }else if(d == 1){
            if(a[i] > a[i+1]){
                d = 0;
                ans++;
            }
        }else{
            if(a[i] < a[i+1]){
                d = 0;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
