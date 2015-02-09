#include <iostream>
using namespace std;

double check(double x1, double y1, double x2, double y2, double ax, double ay){
    return (x1 - x2)*(ay - y1) + (y1 - y2)*(x1 - ax);
}

int main(){
    double ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    int n;
    double x1,y1,x2,y2;
    cin >> n;
    cin >> x1 >> y1;
    int bbx=x1;
    int bby=y1;
    int count = 0;
    for(int i=0;i<n;i++){
        if(i == n-1){
            x2 = bbx;
            y2 = bby;
        }else{
            cin >> x2 >> y2;
        }
        if(check(ax,ay,bx,by,x1,y1)*check(ax,ay,bx,by,x2,y2) < 0 && check(x1,y1,x2,y2,ax,ay)*check(x1,y1,x2,y2,bx,by) < 0){
            //cout << "CROSS\n";
            count++;
        }else{
            //cout << "NOT CROSS\n";
        }
        x1 = x2;
        y1 = y2;
    }
    cout << ((count/2) + 1) << '\n';
    return 0;
}
