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
    string ans = "NO";
    if(s == "AKIHABARA") ans = "YES";
    if(s == "AKIHABAR") ans = "YES";
    if(s == "AKIHABRA") ans = "YES";
    if(s == "AKIHABR") ans = "YES";
    if(s == "AKIHBARA") ans = "YES";
    if(s == "AKIHBAR") ans = "YES";
    if(s == "AKIHBRA") ans = "YES";
    if(s == "AKIHBR") ans = "YES";

    if(s == "KIHABARA") ans = "YES";
    if(s == "KIHABAR") ans = "YES";
    if(s == "KIHABRA") ans = "YES";
    if(s == "KIHABR") ans = "YES";
    if(s == "KIHBARA") ans = "YES";
    if(s == "KIHBAR") ans = "YES";
    if(s == "KIHBRA") ans = "YES";
    if(s == "KIHBR") ans = "YES";

    cout << ans << endl;
    return 0;
}
