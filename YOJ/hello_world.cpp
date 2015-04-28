#include <iostream>
using namespace std;

int main(){
    int T,a;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> a;
        if(a == 1){
            cout << "Hello!\n";
        }else{
            cout << "World!\n";
        }
    }
    return 0;
}
