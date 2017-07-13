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
#include <tuple>
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
    int n, a, b, c;cin >> n >> a >> b;
    c = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        int t;cin >> t;
        if(t == 1){
            if(a > 0){
                a--;
            }else if(b > 0){
                c++;
                b--;
            }else if(c > 0){
                c--;
            }else{
                ans++;
            }
        }else{
            if(b > 0){
                b--;
            }else{
                ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
