#include <iostream>
using namespace std;

int main(){
    while(1){
        int h;
        cin >> h;
        if(h == 0) break;

        int data[10][5];
        for(int i=h-1;i>=0;i--){
            for(int j=0;j<5;j++){
                cin >> data[i][j];
            }
        }
        int score=0;
        while(1){
            bool flag=true;
            for(int i=0;i<h;i++){
                int bn = data[i][0];
                int count = 1;
                for(int j=1;j<5;j++){
                    if(data[i][j] == bn && data[i][j] != 0){
                        count++;
                        bn = data[i][j];
                        switch(count){
                        case 3:
                            score += 3*data[i][j];
                            data[i][j] = data[i][j-1] = data[i][j-2] = 0;
                            flag = false;
                            break;
                        case 4:
                        case 5:
                            score += data[i][j];
                            data[i][j] = 0;
                            flag = false;
                            break;
                        default:
                            break;
                        }
                    }else{
                        count = 1;
                        bn = data[i][j];
                    }
                }
            }

            for(int i=0;i<5;i++){
                int count=0;
                for(int j=0;j<h;j++){
                    if(data[j][i] != 0){
                        data[count][i] = data[j][i];
                        count++;
                    }
                }
                for(int j=count;j<h;j++){
                    data[j][i] = 0;
                }
            }

            if(flag) break;
        }

        cout << score << '\n';
    }
    return 0;
}
