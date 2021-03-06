#include <iostream>
using namespace std;

int main(){
    int N;
    int max[4];
    int sikaku[200][2];
    int dif[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    while(cin >> N){
        if(N == 0) break;

        for(int i=0;i<4;i++) max[i] = 0;
        sikaku[0][0] = sikaku[0][1] = 0;

        for(int i=1;i<N;i++){
            int n,d;
            cin >> n >> d;
            for(int j=0;j<2;j++){
                sikaku[i][j] = sikaku[n][j] + dif[d][j];
                max[d] = max[d] < sikaku[i][j]*dif[d][j] ? sikaku[i][j]*dif[d][j] : max[d];
            }
        }
        cout << (max[0] + max[2] + 1) << ' ' << (max[1] + max[3] + 1) << '\n';
    } 
    return 0;
}
