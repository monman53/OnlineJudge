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
    for(int i=0;i<n;i++){
        cin >> a[i];a[i]--;
    }
    int count = 0;
    int now = 0;
    vector<bool> kita(n, false);
    while(true){
        if(kita[now]){
            cout << -1 << endl;
            break;
        }
        kita[now] = true;
        if(now == 1){
            cout << count << endl;
            break;
        }
        now = a[now];
        count++;
    }
    return 0;
}
