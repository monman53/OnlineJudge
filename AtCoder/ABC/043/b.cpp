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
    string ans = "";
    for(auto c : s){
        switch(c){
            case '0':
            case '1':
                ans.push_back(c);
                break;
            case 'B':
                if(ans.size() > 0){
                    ans.pop_back();
                }
                break;
        }
    }
    cout << ans << endl;
    return 0;
}
