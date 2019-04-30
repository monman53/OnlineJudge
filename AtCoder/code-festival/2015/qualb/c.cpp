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
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(a[i] >= b[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    cout << (j==m ? "YES" : "NO") << endl;
    return 0;
}
