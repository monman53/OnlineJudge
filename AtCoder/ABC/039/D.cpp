#include <iostream>
using namespace std;

int main(){
    int h, w;
    int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    cin >> h >> w;
    char data[h][w];
    char ans[h][w];
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        for(int j=0;j<w;j++){
            data[i][j] = s[j];
            ans[i][j] = s[j];
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(data[i][j] == '.'){
                for(int k=0;k<8;k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                        ans[ni][nj] = '.';
                    }
                }
            }
        }
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(data[i][j] == '#'){
                int count = 0;
                for(int k=0;k<8;k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                        if(ans[ni][nj] == '#'){
                            count++;
                        }
                    }
                }
                if(count == 0 && ans[i][j] == '.'){
                    cout << "impossible" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "possible" << endl;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
