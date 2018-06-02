#include <iostream>
using namespace std;

int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

int main() {
    char c[50][50];
    int h, w;

    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> c[i][j];
        }
    }

    string ans = "Yes";

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(c[i][j] == '#'){
                int cnt = 0;

                for(int k=0;k<4;k++){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;

                    if(c[ni][nj] == '#'){
                        cnt++;
                    }
                }

                if(cnt == 0){
                    ans = "No";
                }
            }
        }
    }


    cout << ans << endl;

    return 0;
}
