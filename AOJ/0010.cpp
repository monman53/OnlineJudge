#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n;
    double a,b,c,d,e,f;
    double p,q,r;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d >> e >> f;
        p = ((d-b)*(c*c+d*d-e*e-f*f)-(f-d)*(a*a+b*b-c*c-d*d))/(2*(c-a)*(f-d)-2*(e-c)*(d-b));
        q = ((c-a)*(c*c+d*d-e*e-f*f)-(e-c)*(a*a+b*b-c*c-d*d))/(2*(e-c)*(d-b)-2*(c-a)*(f-d));
        r = sqrt((p-a)*(p-a) + (q-b)*(q-b));
        //p += (p > 0) ? 0.0005 : -0.0005;
        //q += (q > 0) ? 0.0005 : -0.0005;
        //r += (r > 0) ? 0.0005 : -0.0005;
        printf("%.3f %.3f %.3f\n",p,q,r);
    }
    return 0;
}
