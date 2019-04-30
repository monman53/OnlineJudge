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
    vector<int> d(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> d[i];
        sum += d[i];
    }
    sort(d.begin(), d.end());
    int mmax = *max_element(d.begin(), d.end());
    if(n == 1){
        cout << sum << endl;
        cout << d[0] << endl;
        return 0;
    }
    if(n == 2){
        cout << sum << endl;
        cout << abs(d[0]-d[1]) << endl;
        return 0;
    }
    if(sum-mmax < mmax){
        cout << sum << endl;
        cout << mmax - (sum-mmax) << endl;
    }else{
        cout << sum << endl;
        cout << 0 << endl;
    }
    return 0;
}
