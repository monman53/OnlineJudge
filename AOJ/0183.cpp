#include <iostream>
using namespace std;

int main(){
    int checki[8][3] = {{0,0,0},
                    {1,1,1},
                    {2,2,2},

                    {0,1,2},
                    {0,1,2},
                    {0,1,2},

                    {0,1,2},
                    {0,1,2}};

    int checkj[8][3] = {{0,1,2},
                    {0,1,2},
                    {0,1,2},

                    {0,0,0},
                    {1,1,1},
                    {2,2,2},

                    {0,1,2},
                    {2,1,0}};

    while(1){
        char data[3][3];
        for(int i=0;i<3;i++){
            string s;
            cin >> s;
            if(s == "0") return 0;
            for(int j=0;j<3;j++){
                data[i][j] = s[j];
            }
        }

        for(int i=0;i<8;i++){
            if(data[checki[i][0]][checkj[i][0]] == data[checki[i][1]][checkj[i][1]] && data[checki[i][0]][checkj[i][0]] == data[checki[i][2]][checkj[i][2]] && data[checki[i][0]][checkj[i][0]] != '+'){
                cout << data[checki[i][0]][checkj[i][0]] << '\n';
                break;
            }else if(i == 7){
                cout << "NA\n";
            }
        }
    }
}
