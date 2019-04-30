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
    int n;string s;cin >> n >> s;
    map<pair<char, pair<char, char>>, char> m;
    m[{'S', {'o', 'S'}}] = 'S';
    m[{'S', {'o', 'W'}}] = 'W';
    m[{'S', {'x', 'S'}}] = 'W';
    m[{'S', {'x', 'W'}}] = 'S';
    m[{'W', {'o', 'S'}}] = 'W';
    m[{'W', {'o', 'W'}}] = 'S';
    m[{'W', {'x', 'S'}}] = 'S';
    m[{'W', {'x', 'W'}}] = 'W';
    for(auto ss : {"SS", "SW", "WS", "WW"}){
        string ans = ss;
        for(int i=1;i<n-1;i++){
            ans += m[{ans[i], {s[i], ans[i-1]}}];
            // cout << ans << endl;
        }
        bool flag = false;
        for(int i=0;i<n;i++){
            char l = ans[(i-1+n)%n];
            char r = ans[(i+1+n)%n];
            if(m[{ans[i], {s[i], l}}] != r){
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
