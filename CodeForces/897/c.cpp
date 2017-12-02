// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

string sl = "What are you doing while sending \"";
string sc = "\"? Are you busy? Will you send \"";
string sr = "\"?";

char solve(LL n, LL k){
    LL n0 = s0.size();
    if(n == 0){
        if(k < n0){
            return s0[k];
        }else{
            return '.';
        }
    }

    LL m = sl.size() + sc.size() + sr.size();
    LL p = 0LL;
    if(n > 55){
        p = (1LL << 62);
    }else{
        if(n == 1){
            p = n0;
        }else{
            p = ((1LL << n-1)-1LL)*m + (1LL << n-1LL)*n0;
        }
    }
    LL nl = sl.size();
    LL nc = sc.size();
    LL nr = sr.size();

    if(k < nl){
        return sl[k];
    }
    k -= nl;

    if(k < p){
        return solve(n-1, k);
    }
    k -= p;

    if(k < nc){
        return sc[k];
    }
    k -= nc;

    if(k < p){
        return solve(n-1, k);
    }
    k -= p;

    if(k < nr){
        return sr[k];
    }

    return '.';
}

int main() {
    std::ios::sync_with_stdio(false);
    LL q;cin >> q;
    for(LL i=0;i<q;i++){
        LL n, k;cin >> n >> k;k--;
        cout << solve(n, k);
    }
    cout << endl;
    return 0;
}
