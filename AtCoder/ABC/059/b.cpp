// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

string solve(string a, string b){
    if(a.size() < b.size()) return "LESS";
    if(a.size() > b.size()) return "GREATER";
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) continue;
        if(a[i] < b[i]) return "LESS";
        if(a[i] > b[i]) return "GREATER";
    }
    return "EQUAL";
}

int main() {
    std::ios::sync_with_stdio(false);
    string a, b;cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
