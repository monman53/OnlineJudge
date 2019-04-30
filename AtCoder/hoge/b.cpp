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
    string s;cin >> s;
    map<char, char> m;
    m['i'] = 'i';
    m['w'] = 'w';
    m['('] = ')';
    m[')'] = '(';
    int ans = 0;
    int n = s.size();
    for(int i=0;i<n/2;i++){
        if(m[s[i]] != s[n-i-1]) ans++;
    }
    if(n%2 == 1){
        if(s[n/2] == '(' || s[n/2] == ')') ans++;
    }
    cout << ans << endl;
    return 0;
}
