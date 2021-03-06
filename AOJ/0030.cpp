#include <iostream>
using namespace std;

int n,s;
bool use[10];

int dfs(int count,int sum,int min){
    if(count == n){
        return (sum == s) ? 1 : 0;
    }
    int ret=0;
    for(int i=min;i<10;i++){
        if(!use[i]){
            use[i] = true;
            ret += dfs(count+1, sum+i, i+1);
            use[i] = false;
        }
    }
    return ret;
}

int main(){
    while(1){
        cin >> n >> s;
        if(n == 0 && s == 0) break;

        for(int i=0;i<10;i++) use[i] = false;
        cout << dfs(0,0,0) << '\n';
    }
    return 0;
}
