// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string s;cin >> s;
    if(s.size() == 1){
        s[0]--;
        cout << 1 << s[0] << endl;
        return 0;
    }
    LL sum = 0;
    for(auto c : s){
        sum += c - '0';
    }
    string ans = "";
    while(sum >= 9){
        ans.pb('9');
        sum -= 9;
    }
    if(sum > 0){
        ans.pb('0'+sum);
    }
    reverse(ans.begin(), ans.end());
    if(s == ans){
        if(s[0] == '9'){
            s[0] = '8';
            cout << 1 << s << endl;
        }else{
            s[0]++;
            s[1]--;
            cout << s << endl;
        }
    }else{
        cout << ans << endl;
    }
    return 0;
}
