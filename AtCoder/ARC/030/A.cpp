#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    if(k == 1){
        cout << "YES\n";
    }else{
        if(k <= n/2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
