#include <iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    bool flag;
    for(int i=3;;i+=2){
        if(!isPrime(i)){
            flag = false;
            for(int j=2;j<i;j++){
                if(isPrime(j)){
                    for(int k=1;j+2*k*k<=i;k++){
                        if(j+2*k*k == i){
                            cout << "i= " << j << " + 2*" << k << "^2\n";
                            flag = true;
                        }
                    }
                }
            }
            if(!flag){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}

