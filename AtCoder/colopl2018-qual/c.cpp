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

// 最大公約数
LL gcd(LL x, LL y) {
    return y ? gcd(y, x%y) : x;
}

int n = 0;
bool g[18][18];

int main() {
    std::ios::sync_with_stdio(false);
    LL a, b;cin >> a >> b;
    vector<LL> o, e;
    for(LL i=0LL;a+i<=b;i++){
        if((a+i)%2LL == 1LL){
            o.push_back(a+i);
        }else{
            e.push_back(a+i);
        }
    }
    n = o.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(gcd(o[i], o[j]) == 1LL){
                g[i][j] = true;
            }else{
                g[i][j] = false;
            }
        }
    }
    int ans = 0;
    for(int k=0;k<(1<<n);k++){
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(((k >> i)&1) && ((k >> j)&1)){
                    if(!g[i][j]) flag = false;
                }
            }
        }
        if(flag){
            ans++;
            for(auto ee : e){
                bool flag2 = true;
                for(int i=0;i<n;i++){
                    if((k >> i)&1){
                        if(gcd(o[i], ee) != 1LL){
                            flag2 = false;
                        }
                    }
                }
                if(flag2){
                    ans++;
                    //cout << k << " " << ee << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
