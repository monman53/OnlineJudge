// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int sum(int n) {
    int ret = 0;
    while(n > 0){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;cin >> n;
    bool flag = true;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) flag = false;
    }
    if(n == 2) flag = true;
    if(n == 1){
        cout << "Not Prime" << endl;
        return 0;
    }

    if(flag){
        cout << "Prime" << endl;
        return 0;
    }

    if(n%10 != 5 && n%2 != 0 && sum(n)%3 != 0){
        cout << "Prime" << endl;
        return 0;
    }else{
        cout << "Not Prime" << endl;
        return 0;
    }
}
