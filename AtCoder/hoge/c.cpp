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

map<char, char> m;

int dfs(string l, string r) {
    int ret = 0;
    if(l.size() == 0){
        return 0;
    }
    for(int i=0;i<int(r.size());i++){
        if(m[l[0]] == r[i]){
            ret = max(ret, dfs(l.substr(1), r.substr(i+1)) + 1);
        }
    }
    ret = max(ret, dfs(l.substr(1), r));
    return ret;
}

int main() {
    m['('] = ')';
    m[')'] = '(';
    m['['] = ']';
    m[']'] = '[';
    m['{'] = '}';
    m['}'] = '{';
    string s;cin >> s;
    int c;
    for(int i=0;i<int(s.size());i++){
        if(s[i] == 'w') c = i;
    }

    string l = s.substr(0, c-1);
    string r = s.substr(c+2, int(s.size()) - c+1);

    reverse(r.begin(), r.end());

    cout << dfs(l, r)*2 + 3 << endl;
    return 0;
}
