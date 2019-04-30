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
    vector<LL> sum(100005, 0LL);
    int n;LL k;cin >> n >> k;
    for(int i=0;i<n;i++){
        int a, b;cin >> a >> b;
        sum[a] += LL(b);
    }
    LL now = 0;
    for(int i=0;i<100005;i++){
        if(now < k && k <= now+sum[i]){
            cout << i << endl;
            return 0;
        }
        now += sum[i];
    }
    return 0;
}
