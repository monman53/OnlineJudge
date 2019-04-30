#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] = i;
    }
    bool flag = true;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }
    while(flag){
        flag = false;
        int buf;
        for(int i=0;i<n;i++){
            if(i != 0){
                buf = dp[i];
                dp[i] = min(dp[i], dp[i-1] + 1);
                if(dp[i] != buf){
                    flag = true;
                }
            }
            buf = dp[i];
            dp[a[i]] = min(dp[a[i]], dp[i]+1);
            if(dp[i] != buf){
                flag = true;
            }
        }
        for(int i=n-2;i>=0;i--){
            buf = dp[i];
            dp[i] = min(dp[i], dp[i+1]+1);
            if(dp[i] != buf){
                flag = true;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
