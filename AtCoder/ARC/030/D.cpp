#include <iostream>
using namespace std;

int sum[200001];

int main(){
    int n,q,x,c,a,b,v,c,d;
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> x;
        sum[i] = sum[i-1] + x;
    }

    for(int i=0;i<q;i++){
        cin >> c;
        switch(c){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }

    return 0;
}
