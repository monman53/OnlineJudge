#include <iostream>
using namespace std;

int main(){
    while(1){
        bool card[201][2];
        //int score[2];
        int count[2];
        int n,a;
        cin >> n;
        if(n == 0) break;
        //score[0] = score[1] = 0;
        count[0] = count[1] = n;
        for(int i=1;i<=2*n;i++){
            card[i][0] = false;
            card[i][1] = true;
        }
        for(int i=0;i<n;i++){
            cin >> a;
            card[a][0] = true;
            card[a][1] = false;
        }
        int turn = 0;
        int ba = 0;
        while(1){
            for(int i=1;i<=2*n;i++){
                if(card[i][turn] && i > ba){
                    ba = i;
                    card[i][turn] = false;
                    count[turn]--;
                    break;
                }else if(i == 2*n){
                    ba = 0;
                }
            }
            if(count[turn] == 0) break;
            turn = 1 - turn;
        }
        cout << count[1] << '\n' << count[0] << '\n';
    }
    return 0;
}
