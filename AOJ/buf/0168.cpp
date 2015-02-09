#include <iostream>
using namespace std;

int dp[34];
int n;
int data[31];

int rec(int i){
    if(dp[i] >= 0){
        return dp[i];
    }
    int res;
    if(i > n){
        res = 0;
    }else if(i == n){
        res = 1;
    }else{
        res = rec(i+1) + rec(i+2) + rec(i+3);
        //cout << "kita";
    }
    return dp[i] = res;
}

int main(){
    while(1){
        for(int i=0;i<34;i++){
            dp[i] =-1;
        }
        cin >> n;
        if(n == 0) break;
        cout << (rec(0)/3650 + 1) << '\n';
    }
    return 0;
}

