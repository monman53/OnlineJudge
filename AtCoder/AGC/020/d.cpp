// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)
#define inc(i, l, r)   for(long long i=(l);i<(r);i++)
#define dec(i, l, r)   for(long long i=(r)-1;i>=(l);i--)
#define se          second
#define fi          first

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

string solve2(int a, int b) {
    string s;
    if(a>=b){
        int k = (a+b+1-1)/(b+1);
        int n = a+b;
        int cnta = 0;
        inc(i, 0, n){
            int res = n-i-1;
            if(cnta == k){
                s.push_back('B');
                b--;
                cnta = 0;
            }else{
                if(res/(k+1) <= a-1){
                    s.push_back('A');
                    a--;
                    cnta++;
                }else{
                    s.push_back('B');
                    cnta=0;
                    b--;
                }
            }
        }
    }
    return s;
}

string solve(int a, int b, int c, int d){
    string s;
    if(a < b){
        s = solve2(b, a);
        reverse(s.begin(), s.end());
        for(auto &c : s){
            if(c == 'A'){
                c = 'B';
            }else{
                c = 'A';
            }
        }
    }else{
        s = solve2(a, b);
    }
    cout << s << endl;
    return s.substr(c-1, d-c+1);
}

int main() {
    std::ios::sync_with_stdio(false);
    int q;cin >> q;
    inc(i, 0, q){
        int a, b, c, d;cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << endl;
    }
    return 0;
}
