// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

string f(string s){
    if(s == "Left") return "<";
    if(s == "Right") return ">";
    return "A";
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    cout << f(s);
    while(cin >> s){
        cout << " " << f(s);
    }
    cout << endl;
    return 0;
}
