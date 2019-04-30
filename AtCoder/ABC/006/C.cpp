#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    bool flag = false;

    for(int y=0;y<=N;y++){
        if((M-2*N-y)%2 == 0 && M-2*N-y >= 0){
            int z = (M-2*N-y)/2;
            if(M-2*N == y+2*z && N-y-z >= 0 && y >= 0 && z >= 0){
                cout << (N-y-z) << " " << y << " " << z << endl;
                flag = true;
            }
        }
        if(flag) break;
    }

    if(!flag){
        cout << "-1 -1 -1" << endl;
    }

    return 0;
}
