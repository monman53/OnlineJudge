#include <iostream>
using namespace std;

int main(){
    int m,n;
    cin >> m;
    int x,y,w,h;
    int x1,y1,x2,y2;
    
    for(int i=0;i<m;i++){
        cin >> x >> y >> w >> h;
        x1 = x;
        y1 = y;
        x2 = x1 + w;
        y2 = y1 + h;

        cin >> n;
        int X,Y;
        int count = 0;
        for(int j=0;j<n;j++){
            cin >> X >> Y;
            if(X >= x1 && X <= x2 && Y >= y1 && Y <= y2){
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}
