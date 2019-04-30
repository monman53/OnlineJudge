// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    vector<int> cnt(26, 0);
    for(auto c : s) cnt[c-'a']++;
    int ocnt = 0;
    for(auto n : cnt) ocnt += n%2;
    int n = s.size();
    if(ocnt == 0){
        cout << n << endl;
    }else{
        cout << (n-ocnt)/2/ocnt*2+1 << endl;
    }
    return 0;
}
