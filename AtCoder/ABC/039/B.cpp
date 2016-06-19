#include <iostream>
using namespace std;

int main(){
    long x;
    cin >> x;

    for(long i=1;i<=1000;i++){
        if(i*i*i*i == x){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
