// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    int a, b, c, d;cin >> a >> b >> c >> d;
    if(a == 0 || b == 0 || c == 0 || d == 0){
        cout << "\"";
    }
    int n = s.size();
    for(int i=0;i<n;i++){
        cout << s[i];
        if(i+1 == a || i+1 == b || i+1 == c || i+1 == d){
            cout << "\"";
        }
    }
    cout << endl;
    return 0;
}
