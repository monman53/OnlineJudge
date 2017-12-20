// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    bitset<8> bit;
    int count = 0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        if(a < 400){
            bit[0] = true;
        }else if(a < 800){
            bit[1] = true;
        }else if(a < 1200){
            bit[2] = true;
        }else if(a < 1600){
            bit[3] = true;
        }else if(a < 2000){
            bit[4] = true;
        }else if(a < 2400){
            bit[5] = true;
        }else if(a < 2800){
            bit[6] = true;
        }else if(a < 3200){
            bit[7] = true;
        }else{
            count++;
        }
    }

    cout << max(1, int(bit.count())) << " " << int(bit.count())+count << endl;

    return 0;
}
