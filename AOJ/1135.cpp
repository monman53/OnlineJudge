#include <iostream>
using namespace std;

int main(){
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int moto,y,n;
        int max = 0;
        cin >> moto >> y >> n;
        for(int j=0;j<n;j++){
            int type,tesuryo,A,B,ruikei;
            double r;
            cin >> type >> r >> tesuryo;
            A = moto;
            ruikei = 0;
            for(int k=0;k<y;k++){
                B = A*r;
                if(type == 0){
                    ruikei += B;
                }else{
                    A += B;
                }
                A -= tesuryo;

                if(k == y-1){
                    A += ruikei;
                    if(A > max){
                        max = A;
                    }
                }
            }
        }
        cout << max << '\n';
    }
    return 0;
}
