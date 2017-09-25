// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        if(s.find(a) != s.end()){
            s.erase(a);
        }else{
            s.insert(a);
        }
    }
    cout << s.size() << endl;
    return 0;
}
