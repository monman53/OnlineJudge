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
    vector<LL> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    LL ans[2] = {0, 0};
    for(int i=0;i<2;i++){
        LL sum = 0LL;
        for(int j=0;j<n;j++){
            if(j%2 == i && sum+a[j] <= 0){
                ans[i] += 1-(sum+a[j]);
                sum = 1;
            }else if(j%2 == 1-i && sum+a[j] >= 0){
                ans[i] += 1+(sum+a[j]);
                sum = -1;
            }else{
                sum += a[j];
            }
        }
    }
    cout << min(ans[0], ans[1]) << endl;
    return 0;
}
