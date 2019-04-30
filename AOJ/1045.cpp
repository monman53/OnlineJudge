#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int sum, data[20], n, mmin;

void solve(int i, int ssum){
    if(i == n){
        mmin = min(mmin, abs(ssum - (sum - ssum)));
        return;
    }
    solve(i+1, ssum+data[i]);
    solve(i+1, ssum);
}

int main(){
    while(1){
        cin >> n;

        if(n == 0){
            break;
        }

        mmin = 999999999;
        sum = 0;
        for(int i=0;i<n;i++){
            cin >> data[i];
            sum += data[i];
        }
        solve(0, 0);
        cout << mmin << endl;
    }
}
