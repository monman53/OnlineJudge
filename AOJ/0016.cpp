#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    double x=0,y=0;
    int bt=0;
    while(1){
        int d,t;
        scanf("%d,%d",&d,&t);
        if(d == 0 && t == 0) break;
        x += double(d)*sin(double(bt)*M_PI/180.0);
        y += double(d)*cos(double(bt)*M_PI/180.0);
        bt += t;
    }
    cout << int(x) << '\n' << int(y) << '\n';
    return 0;
}
