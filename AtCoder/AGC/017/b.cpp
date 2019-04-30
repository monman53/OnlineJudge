// header {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    26
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
#define INF         1000000005

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    ll n, a, b, c, d;cin >> n >> a >> b >> c >> d;
    bool ans = false;
    for(int m=0;m<n;m++){
        if(c*(n-1-m)-d*m <= b-a && b-a <= -c*m+(n-1-m)*d){
            ans = true;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
