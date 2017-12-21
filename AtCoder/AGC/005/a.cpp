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
    int n = s.size();
    int l = 0;
    int r = 0;
    int count = 0;
    while(l < n && r < n){
        while(s[l] == 'T'){
            l++;
        }
        while(s[r] == 'S'){
            r++;
        }
        if(l >= n || r >= n) break;
        if(l >= r){
            r++;
        }else{
            count++;
            l++;
            r++;
        }
    }
    cout << n-2*count << endl;
    return 0;
}
