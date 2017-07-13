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
#include <cstring>
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

bool y[9000000];
int main() {
    while(true){
        int m, n;cin >> m >> n;
        if(m == 0) break;
        memset(y, false, sizeof(y));
        int count = 0;
        for(int i=m;i<9000000;i++){
            if(!y[i]){
                if(count == n){
                    cout << i << endl;
                    break;
                }
                count++;
                for(int j=i;j<9000000;j+=i){
                    y[j] = true;
                }
            }
        }
    }
    return 0;
}
