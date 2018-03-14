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

// うるう年判定
// ARC002B
bool isUruu(int y) {
    return (y%4 == 0 && y%100 != 0) || y%400 == 0;
}

// 西暦y年のm月は何日あるか
// ARC002B
int month(int y, int m) {
    if(m ==  1) return 31;
    if(m ==  2) return 28 + (isUruu(y) ? 1 : 0);
    if(m ==  3) return 31;
    if(m ==  4) return 30;
    if(m ==  5) return 31;
    if(m ==  6) return 30;
    if(m ==  7) return 31;
    if(m ==  8) return 31;
    if(m ==  9) return 30;
    if(m == 10) return 31;
    if(m == 11) return 30;
    if(m == 12) return 31;
    return 0;
}

// 文字列sの文字cによるsplit
// ABC033
vector<string> split(string &s, char c) {
    vector<string> ret;
    int b = 0;
    int n = s.size();
    int i;
    for(i=0;i<n;i++){
        if(s[i] == c){
            ret.push_back(s.substr(b, i-b));
            b = i+1;
        }
    }
    ret.push_back(s.substr(b, i-b));
    return ret;
}

int h[13][32];

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    inc(i, 0, n){
        string s;cin >> s;
        auto ss = split(s, '/');
        h[stoi(ss[0])][stoi(ss[1])] = 1;
    }

    int d = 0;
    int cnt = 0;
    int ans = 0;
    int hcnt = 0;
    inc(i, 1, 13){
        inc(j, 1, month(2012, i)+1){
            d++;
            if(d%7 < 2){
                cnt++;
                if(h[i][j]){
                    hcnt++;
                }
            }else if(h[i][j]){
                cnt++;
            }else{
                if(hcnt > 0){
                    cnt++;
                    hcnt--;
                }else{
                    cnt = 0;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
