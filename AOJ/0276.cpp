#include <iostream>
using namespace std;

int main(){
    while(1){
        int a,b;
        cin >> a;
        if(cin.eof()) break;
        cin >> b;
        cout << a - b << '\n';
    }
    return 0;
}
