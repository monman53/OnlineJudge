#include <iostream>
#include <cmath>
using namespace std;

bool isPentagonal(long long int n){
    long long int x=(1+sqrt(1+24*n))/6;
    if(x*(3*x-1)/2 == n) return true;
    return false;
}

bool isTriangle(long long int n){
    long long int x=(-1+sqrt(1+8*n))/2;
    if(x*(x+1)/2 == n) return true;
    return false;
}

bool isHexagonal(int n){
    int x=(1+sqrt(1+8*n))/4;
    if(x*(2*x-1) == n) return true;
    return false;
}

int main(){
    int count=0;
    long long int hex;
    for(int i=1;count<3;i++){
        hex = i*(2*i-1);
        //cout << hex << '\n';
        if(isTriangle(hex) && isPentagonal(hex)){
            cout << hex << '\n';
            count++;
        }
    }
    return 0;
}
