#include <iostream>
using namespace std;

char data[1000001][1000001];
int l[50],t[50],r[50],b[50];
int n;
int minx,maxx,miny,maxxy;

int main(){    
    while(1){
        cin >> n;
        if(n == 0) break;
        minx=1000001;
        miny=1000001;
        maxx=0;
        maxy=0;
        for(int i=0;i<n;i++){
            cin >> l[i] >> t[i] >> r[i] >> b[i];
            if(l[i] < minx) minx = l[i];
            if(r[i] > maxx) maxx = r[i];
            if(b[i] < miny) miny = b[i];
            if(t[i] > maxy) maxy = t[i];
        }
        for(int i=minx;i<=maxx;i++){
            for(int j=miny;j<=
        for(int i=0;i<n;i++){

        }
    }
    return 0;
}
