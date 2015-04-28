#include <iostream>
using namespace std;

int main(){
    int n,p;
    while(1){
        cin >> n >> p;
        if(n==0 && p==0){
            break;
        }
        int data[50];
        int wan = p;
        int turn = 0;
        //init
        for(int i=0;i<n;i++){
            data[i] = 0;
        }
        while(1){
            if(wan > 0){
                data[turn]++;
                wan--;
            }else{
                wan = data[turn];
                data[turn] = 0;
            }
            if(data[turn] == p){
                cout << turn << '\n';
                break;
            }
            turn = (turn+1)%n;
        }
    }

    return 0;
}
