#include <iostream>
using namespace std;

int main(){
    bool w;
    int T;
    long long int N;
    cin >> T;
    for(int i=0;i<T;i++){
        w = false;
        cin >> N;
        while(N>0){
            if(N%2==0){
                N -= N/2;
            }else{
                N -= (N-1)/2;
                if(N==1){
                    N = 0;
                }
            }
            w = !w;
        }
        if(w){
            cout << "First\n";
        }else{
            cout << "Second\n";
        }
    }
    return 0;
}
