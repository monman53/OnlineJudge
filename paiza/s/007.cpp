// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    vector<LL> ans(26, 0);
    stack<LL> st;
    int n = s.size();
    LL m = 0;
    st.push(1);
    inc(i, 0, n){
        char c = s[i];
        if(is_digit(c)){
            m = m*10 + (c-'0');
        }else{
            if(c == '('){
                st.push(st.top()*m);
                m = 0;
            }else if(c == ')'){
                st.pop();
            }else{
                if(m != 0){
                    ans[c-'a'] += st.top()*m;
                }else{
                    ans[c-'a'] += st.top();
                }
            }
            m = 0;
        }
    }
    inc(i, 0, 26){
        cout << char('a'+i) << " " << ans[i] << endl;
    }
    return 0;
}
