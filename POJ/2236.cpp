#include <iostream>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        cout << x << y << '\n';
    }
    while(1){
        char c;
        cin >> c;
        if(cin.eof()) break;
        cout << c << '\n';
        if(c == 'O'){
            int p;
            cin >> p;
        }else{
            int f,t;
            cin >> f >> t;
        }
    }
    return 0;
}
