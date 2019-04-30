#include <iostream>
#include <cmath>
using namespace std;

bool isPentagonal(int n){
    int x=(1+sqrt(1+24*n))/6;
    if(x*(3*x-1)/2 == n) return true;
    return false;
}

int main(){
    int pi,pj;
    for(int i=2;;i++){
        cout << i << '\n';
        pi = i*(3*i-1)/2;
        for(int j=i-1;j>0;j--){
            pj = j*(3*j-1)/2;
            if(isPentagonal(pi + pj) && isPentagonal(pi - pj)){
                cout << pi << ' ' << pj << '\n';
                cout << (pi - pj) << '\n';
                return 0;
            }
        }
    }
    return 0;
}
