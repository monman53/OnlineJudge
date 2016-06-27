#include <iostream>
using namespace std;

int main(){
    int h, hh, w, ww;
    cin >> h >> w >> hh >> ww;
    if(h == hh || h == ww || w == hh || w == ww){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
