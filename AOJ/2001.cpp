#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int n,m,a;
        bool line[1001][101];
        int goal[101];
        for(int i=0;i<1001;i++) for(int j=0;j<101;j++) {line[i][j] = false;goal[j] = j;}

        cin >> n >> m >> a;
        if(n+m+a == 0) break;

        for(int i=0;i<m;i++){
            int h,p,q;
            cin >> h >> p >> q;
            line[h][min(p, q)] = true;
        }

        for(int i=1;i<1001;i++){
            for(int j=1;j<101;j++){
                if(line[i][j]){
                    int buf = goal[j];
                    goal[j] = goal[j+1];
                    goal[j+1] = buf;
                }
            }
        }

        cout << goal[a] << '\n';
    }
    return 0;
}

