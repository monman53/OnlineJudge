#include <iostream>
using namespace std;

int main() {
    char map[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> map[i][j];
        }
    }

    for(int i=3;i>=0;i--){
        for(int j=3;j>=0;j--){
            cout << map[i][j];
            if(j != 0){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
