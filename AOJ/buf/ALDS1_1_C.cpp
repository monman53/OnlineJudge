#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n==2){
        return true;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int count=0;
    int n,p;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p;
        if(isPrime(p)){
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}
