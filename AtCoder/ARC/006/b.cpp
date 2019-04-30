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

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int w, n;cin >> w >> n;
    cin.ignore();
    w = w*2-1;
    vector<string> c(n);
    inc(i, 0, n){
        getline(cin, c[i]);
    }

    string s;
    getline(cin, s);
    int now;
    inc(i, 0, w){
        if(s[i] == 'o'){
            now = i;
        }
    }

    reverse(c.begin(), c.end());

    inc(i, 0, n){
        //cout << now << endl;
        //cout << c[i] << endl;
        if(now > 0){
            if(c[i][now-1] == '-'){
                now -= 2;
                continue;
            }
        }
        if(now < w-1){
            if(c[i][now+1] == '-'){
                now += 2;
                continue;
            }
        }
    }
    cout << now/2+1 << endl;
    return 0;
}
