#include <iostream>
#include <cstdio>
using namespace std;

bool ans(double a,double b,double c,double d,double e,double f,double g,double h){
    double i,j,k,l;
    i = c - a;
    j = d - b;
    k = g - e;
    l = h - f;
    double s;
    s = i*l - j*k;
    //printf("%.20f",s);
    if((d-b)/(c-a) == (h-f)/(g-e)){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    float a,b,c,d,e,f,g,h;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        //scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h);
        //printf("%.20f",h);
        //cout << ((ans(a,b,c,d,e,f,g,h)) ? "YES\n" : "NO\n");
        cout << (((d-b)/(c-a) == (h-f)/(g-e)) ? "YES\n" : "NO\n");
    }
    return 0;
}
                 
