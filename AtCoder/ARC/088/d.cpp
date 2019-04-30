// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int n;
int dir[100000];

int f[100000];

int calc(int k) {
    memset(f, 0, sizeof(f));
    int res = 0;
    int sum = 0;
    for(int i=0;i+k<=n;i++){
        if((dir[i]+sum)%2 != 0){
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if(i-k+1 >= 0){
            sum -= f[i-k+1];
        }
    }

    for(int i=n-k+1;i<k;i++){
        if((dir[i]+sum)%2 != 0){
            return -1;
        }
        if(i-k+1>=0){
            sum -= f[i-k+1];
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;cin >> s;
    n = s.size();
    for(int i=0;i<n;i++){
        dir[i] = s[i]-'0';
    }
    int l = 0;
    int r = n+1;
    while(r-l>1){
        int mid = (l+r)/2;
        if(calc(mid) >= 0){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
