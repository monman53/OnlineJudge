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
    int a, b, n;cin >> a >> b >> n;
    string s;cin >> s;
    inc(i, 0, n){
        if(s[i] == 'S'){
            a = max(0, a-1);
        }
        if(s[i] == 'C'){
            b = max(0, b-1);
        }
        if(s[i] == 'E'){
            if(a > b){
                a = max(0, a-1);
            }else if(b > a){
                b = max(0, b-1);
            }else if(a > 0 && a == b){
                a = max(0, a-1);
            }
        }
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}
