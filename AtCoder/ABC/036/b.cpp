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
    int n;cin >> n;
    char c[n][n];
    for(int i=0;i<n;i++){
        string s;cin >> s;
        for(int j=0;j<n;j++){
            c[i][j] = s[j];
        }
    }
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}
