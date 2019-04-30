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
    int n;cin >> n;
    string s;cin >> s;
    deque<char> dq;
    int l = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            dq.push_back('(');
            l++;
        }else{
            if(l > 0){
                dq.push_back(')');
                l--;
            }else{
                dq.push_front('(');
                dq.push_back(')');
            }
        }
    }
    while(l > 0){
        dq.push_back(')');
        l--;
    }
    for(auto c : dq){
        cout << c;
    }
    cout << endl;
    return 0;
}
