#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
    
int n, m;
int x[20];
int y[20];

struct Data{
    int left, right;
};
Data data[20];

bool bou[20];

int solve(int ii){
    int ret = 0;
    if(ii == n+1){
        return 1;
    }
    for(int i=1;i<=n;i++){
        data[i].left = 0;
        data[i].right = 0;
    }
    for(int i=0;i<m;i++){
        if(x[i] != ii &&  y[i] != ii){
            data[x[i]].right++;
            data[y[i]].left++;
        }
    }
    for(int i=data[ii].left+1;i<=n-data[ii].right;i++){
        if(!bou[i]){
            bou[i] = true;
            ret += solve(ii+1);
            bou[i] = false;
        }
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        data[i].left = 0;
        data[i].right = 0;
        bou[i] = false;
    }
    for(int i=0;i<m;i++){
        cin >> x[i] >> y[i];
        data[x[i]].right++;
        data[y[i]].left++;
    }
    
    cout << solve(1) << endl;

    return 0;
}
