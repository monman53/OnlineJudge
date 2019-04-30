#include <iostream>
using namespace std;

int main(){
    long long int n,s;
    long long int c[10000];
    long long int y[10000];
    cin >> n >> s;
    long long int sum = 0;
    for(int i=0;i<n;i++){
        cin >> c[i] >> y[i];
        long long int min = c[i]*y[i];
        int j;
        if(i - c[i]/s - 1< 0) j = 0;
        else j = i - c[i]/s - 1;

        for(;j<i;j++){
            if(c[j] < c[i]){
                long long int cost = c[j]*y[i] + s*(i-j)*y[i];
                if(cost < min) min = cost;
            }
        }
        sum += min;
    }
    cout << sum << '\n';
    return 0;
}
