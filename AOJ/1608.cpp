// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
// #include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    while(true){
        int n;cin >> n;
        if(n == 0) break;
        vector<int> a(n);
        for(auto &aa : a) cin >> aa;
        int ans = 3000000;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j != i){
                    ans = min(ans, abs(a[i] - a[j]));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
