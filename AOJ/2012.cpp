#include <iostream>
using namespace std;

int cal(int e){
    int min = 99999999;
    for(int y=0;y<=1000;y++){
        for(int z=0;z<=100;z++){
            int buf = e+y-y*y+z-z*z*z;
            if(min >= buf && buf >= 0 && buf-y-z <=1000000){
                min = e+y-y*y+z-z*z*z;
            }
        }
    }
    return min;
}

int main(){
    while(1){
        int e;
        cin >> e;
        if(e == 0) break;
        cout << cal(e) << '\n';
    }
    return 0;
}
