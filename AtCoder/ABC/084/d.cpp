// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

#define SIZE 100005

// 素数判定 (エラトステネスのふるい)
bool isPrime[SIZE];
void initIsPrime() {
    for(int i=0;i<SIZE;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<=SIZE;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=SIZE;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int sum[100001];

int main() {
    std::ios::sync_with_stdio(false);
    initIsPrime();
    sum[1] = 0;
    for(int i=1;i<=100000;i++){
        sum[i+1] = sum[i] + (isPrime[i] && isPrime[(i+1)/2]);
    }
    int q;cin >> q;
    for(int i=0;i<q;i++){
        int l, r;cin >> l >> r;r++;
        cout << sum[r]-sum[l] << endl;
    }
    return 0;
}
