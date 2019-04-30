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
    int n;cin >> n;
    string s;cin >> s;
    string ans = "";
    if(s[0] == ')' || n%2 == 1){
        cout << ":(" << endl;
        return 0;
    }
    int cnt = 0;
    inc(i, 0, n){
        if(s[i] == '(') cnt++;
    }
    inc(i, 0, n){
        if(s[i] == '?'){
            if(cnt < n/2){
                s[i] = '(';
                cnt++;
            }else{
                s[i] = ')';
            }
        }
    }
    stack<char> st;
    inc(i, 0, n){
        if(s[i] == '('){
            st.push(s[i]);
        }
        if(s[i] == ')'){
            if(st.size() > 0){
                st.pop();
            }else{
                cout << ":(" << endl;
                return 0;
            }
        }
        if(st.size() == 0 && i < n-1){
            cout << ":(" << endl;
            return 0;
        }
    }
    if(st.size() > 0){
        cout << ":(" << endl;
        return 0;
    }

    cout << s << endl;

    return 0;
}
