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
    int n, a, b;cin >> n >> a >> b;
    int cnt = 0;
    while(n > 0){
        if(cnt%2 == 0){
            n -= a;
        }else{
            n -= b;
        }
        if(n <= 0){
            cout << (cnt%2==0 ? "Ant" : "Bug") << endl;
            break;
        }
        cnt++;
    }
    return 0;
}
