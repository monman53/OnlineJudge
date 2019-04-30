#include <bits/stdc++.h>
using namespace std;

int n;
long long int k;
int cnt[40];

long long int dfs(int i, int f) {
    if(i < 0) return 0;
    
    long long int m = 1LL << i;
    if(f){  // greedy
        return dfs(i-1, 1) + m*max(n - cnt[i], cnt[i]);
    }else{  // not greedy
        if(k >> i & 1){
            return max(dfs(i-1, 1) + m*cnt[i],
                       dfs(i-1, 0) + m*(n - cnt[i]));
        }else{
            return dfs(i-1, 0) + m*cnt[i];
        }
    }
}

int main() {
    // input
    cin >> n >> k;
    for(int i=0;i<n;i++){
        long long int a; cin >> a;
        for(int j=0;j<40;j++){
            cnt[j] += a >> j & 1;
        }
    }
    // output
    cout << dfs(39, 0) << endl;
    return 0;
}
