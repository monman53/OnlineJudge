// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int t;cin >> t;
    for(int i=0;i<t;i++){
        LL a, b, c;cin >> a >> b >> c;
        if(a < b) swap(a, b);
        if(a < c) swap(a, c);
        if(b < c) swap(b, c);
        //cout << a << " " << b << " " << c << endl;
        LL x = (a+b-c)/2;
        LL y = (b+c-a)/2;
        if(abs(b+c-a)%2 == 0 && abs(a+b-c)%2 == 0 && y >= 0 && x >= 0 && x <= a){
            cout << "0 0 " << a << " 0 " << x << " " << y << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
