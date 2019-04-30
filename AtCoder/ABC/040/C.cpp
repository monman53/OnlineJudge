#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int a[100000];
    long cost[100000];
    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i];
        cost[i] = -1;
    }

    cost[0] = 0;
    for(int i=0;i<n-1;i++){
        if(cost[i+1] == -1){
            cost[i+1] = cost[i] + abs(a[i+1] - a[i]);
        }else{
            cost[i+1] = min(cost[i+1], cost[i] +  abs(a[i+1] - a[i]));
        }
        if(i!=n-2){
            cost[i+2] = cost[i] + abs(a[i+2] - a[i]);
        }
    }


    cout << cost[n-1] << endl;

    return 0;
}
