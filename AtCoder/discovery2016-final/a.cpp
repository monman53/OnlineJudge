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
    int n;cin >> n;
    vector<pair<int, int>> v;
    for(int i=1;i<=n;i++){
        int k;cin >> k;
        v.push_back({k, i});
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        int k = v[i].second;
        switch(k){
            case 1: cout << 100000 << endl;break;
            case 2: cout << 50000 << endl;break;
            case 3: cout << 30000 << endl;break;
            case 4: cout << 20000 << endl;break;
            case 5: cout << 10000 << endl;break;
            default: cout << 0 << endl;break;
        }
    }
    return 0;
}
