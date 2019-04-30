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

int n, q;
char t[200005];
int d[200005];
string s;

int isOut(int k) {
    if(k <  0) return -1;
    if(k >= n) return +1;
    int now = k;
    inc(i, 0, q){
        if(s[now] == t[i]){
            now += d[i];
        }
        if(now <  0) return -1;
        if(now >= n) return +1;
    }
    return 0;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    cin >> n >> q;
    cin >> s;
    inc(i, 0, q){
        char dd;
        cin >> t[i] >> dd;
        if(dd == 'L'){
            d[i] = -1;
        }else{
            d[i] = +1;
        }
    }

    if(n == 1){
        if(isOut(0) == 0){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }

    int ok = -1;
    int ng = n;
    while(ng-ok>1){
        int c = (ok+ng)/2;
        if(isOut(c) == -1){
            ok = c;
        }else{
            ng = c;
        }
    }
    int l = ok;

    ok = n;
    ng = -1;
    while(ok-ng>1){
        int c = (ok+ng)/2;
        if(isOut(c) == +1){
            ok = c;
        }else{
            ng = c;
        }
    }
    int r = ok;
//    inc(i, 0, n){
//        cout << isOut(i) << endl;
//    }
//    cout << l << " " << r << endl;
    cout << r-l-1 << endl;

    return 0;
}
