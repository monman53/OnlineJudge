#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b != 0 ? gcd(b, a % b) : a;
}

int extgcd(int a, int b, int &x, int &y) {
  int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

int main() {
    while(true){
        int a, b, d;cin >> a >> b >> d;
        if(a == 0) break;
        int g = gcd(a, b);
        a /= g;b /= g;d /= g;

        int x, y;
        extgcd(a, b, x, y);
        
        int ans_x = d*x;int ans_y = d*y;
        x *= d;
        y *= d;
        //cout << ans_x << " " << ans_y << endl;

        for(int k=1;;k++){
            int cx = x+k*b;
            int cy = y-k*a;
            if(abs(cx)+abs(cy) > abs(ans_x)+abs(ans_y)){
                break;
            }else if(abs(cx)+abs(cy) == abs(ans_x)+abs(ans_y)){
                if(abs(cx)*a+abs(cy)*b > abs(ans_x)*a+abs(ans_y)*b){
                    break;
                }else{
                    ans_x = cx;
                    ans_y = cy;
                }
            }else{
                ans_x = cx;
                ans_y = cy;
            }
        }
        for(int k=-1;;k--){
            int cx = x+k*b;
            int cy = y-k*a;
            if(abs(cx)+abs(cy) > abs(ans_x)+abs(ans_y)){
                break;
            }else if(abs(cx)+abs(cy) == abs(ans_x)+abs(ans_y)){
                if(abs(cx)*a+abs(cy)*b > abs(ans_x)*a+abs(ans_y)*b){
                    break;
                }else{
                    ans_x = cx;
                    ans_y = cy;
                }
            }else{
                ans_x = cx;
                ans_y = cy;
            }
        }
        cout << abs(ans_x) << " " << abs(ans_y) << endl;
    }
    return 0;
}
