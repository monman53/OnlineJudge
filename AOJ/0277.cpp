#include <iostream>
using namespace std;

int main(){
    int data[5] = {0,6000,4000,3000,2000};
    for(int i=0;i<4;i++){
        int t,n;
        cin >> t >> n;
        cout << data[t]*n << '\n';
    }
    return 0;
}
