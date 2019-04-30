#include <iostream>
#include <algorithm>
using namespace std;

int dp[351][351];
int n;
int data[350][350];

int rec(int i,int j){
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    int res;
    if(i == n){
        res = 0;
    }else{
        res = max(data[i][j] + rec(i+1,j), data[i][j] + rec(i+1,j+1));
    }
    return dp[i][j] = res;
}

int main(){
    for(int i=0;i<351;i++){
        for(int j=0;j<351;j++){
            dp[i][j] = -1;
        }
    }
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> data[i][j];
        }
    }

    cout << rec(0,0) << '\n';

    return 0;
}
