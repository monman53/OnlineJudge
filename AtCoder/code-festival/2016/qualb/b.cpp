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
    int n, a, b;cin >> n >> a >> b;
    string s;cin >> s;
    int ac = 0;
    int bc = 0;
    for(auto c : s){
        if(c == 'a'){
            if(ac+bc < a+b){
                cout << "Yes" << endl;
                ac++;
            }else{
                cout << "No" << endl;
            }
        }else if(c == 'b'){
            if(ac+bc < a+b && bc < b){
                cout << "Yes" << endl;
                bc++;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
