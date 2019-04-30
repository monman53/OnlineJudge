#include <iostream>
using namespace std;

int main(){
    long long int n=1;
    int i;
    cin >> i;
    for(;i>1;i--){
        n *= i;
    }
    cout << n << '\n';
    return 0;
}
