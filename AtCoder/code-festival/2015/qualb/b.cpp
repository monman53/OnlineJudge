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
    int n, m;cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<int, int> mmap;
    for(int i=0;i<n;i++){
        mmap[a[i]]++;
        if(mmap[a[i]] > n/2){
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << "?" << endl;
    return 0;
}
