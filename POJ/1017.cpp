#include <iostream>
using namespace std;

int main(){
    while(1){
        int sum=0;
        int data[7];
        for(int i=0;i<6;i++){
            cin >> data[i+1];
            sum += data[i+1];
        }
        if(sum == 0) break;
        int ans=0;

        //6
        ans += data[6];
        //5
        ans += data[5];
        if(data[5]*11 >= data[1]){
            data[1] = 0;
        }else{
            data[1] -= data[5]*11;
        }
        //4
        ans += data[4];
        if(5*data[4] >= data[2]){
            if((5*data[4] - data[2])*4 >= data[1]){
                data[1] = 0;
            }else{
                data[1] -= (5*data[4] - data[2])*4;
            }
            data[2] = 0;
        }else{
            data[2] -= 5*data[5];
        }
        //3
        if(data[3]%4 == 0){
            ans += data[3]/4;
        }else{
            ans += data[3]/4 + 1;
            switch(data[3]%4){
            case 3:
                if(data[2] > 0){
                    data[2]--;
                    if(data[1] <= 5){
                        data[1] = 0;
                    }else{
                        data[1] -= 5;
                    }
                }
                break;
            case 2:
                if(data[2] <= 3){
                    if(18 - data[2]*4 >= data[1]){
                        data[1] = 0;
                    }else{
                        data[1] -= 18 - data[2]*4;
                    }
                    data[2] = 0;
                }else{
                    if(6 >= data[1]){
                        data[1] = 0;
                    }else{
                        data[1] -= 6;
                    }
                    data[2] -= 3;
                }
                break;
            case 1:
                if(data[2] <= 5){
                    if(27 - data[2]*4 >= data[1]){
                        data[1] = 0;
                    }else{
                        data[1] -= 27 - data[2]*4;
                    }
                    data[2] = 0;
                }else{
                    if(7 >= data[1]){
                        data[1] = 0;
                    }else{
                        data[1] -= 7;
                    }
                    data[2] -= 5;
                }
                break;
            }
        }
        //2
        if(data[2]%9 == 0){
            ans += data[2]/9;
        }else{
            ans += data[2]/9 + 1;
            if(36 - (data[2]%9)*4 >= data[1]){
                data[1] = 0;
            }else{
                data[1] -= 36 - (data[2]&9)*4;
            }
        }
        //1
        if(data[1]%36 == 0){
            ans += data[1]/36;
        }else{
            ans += data[1]/36 + 1;
        }

        cout << ans << '\n';
    }
    return 0;
}
