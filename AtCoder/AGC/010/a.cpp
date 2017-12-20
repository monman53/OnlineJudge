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
    int oc = 0;
    int ec = 0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        if(a%2 == 0){
            ec++;
        }else{
            oc++;
        }
    }

    string ans = "YES";

    if(oc%2 == 1 && ec > 0) ans = "NO";

    cout << ans << endl;

    return 0;
}
