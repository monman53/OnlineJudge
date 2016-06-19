#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int w, h;
int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};
char map[1000][1000];

int par[1000*1000];
int ran[1000*1000];

void init(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            par[w*i + j] = w*i + j;
        }
    }
}

int find(int x){
    if(x == par[x]){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

int unite(int x, int y){
    x = find(x);
    y = find(y);
    if(ran[x] > ran[y]){
        par[y] = x;
    }else{
        par[x] = y;
        if(ran[x] == ran[y]){
            ran[y]++;
        }
    }
}

int main(){
    int ti, tj;

    cin >> w >> h;

    bool shirabeta[1000][1000];
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        for(int j=0;j<w;j++){
            map[i][j] = s[j];
            if(map[i][j] == 't'){
                ti = i;
                tj = j;
                map[i][j] = '.';
            }
            shirabeta[i][j] = false;
        }
    }
    
    init();
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            stack<int> s;
            if(map[i][j] == '.' && !shirabeta[i][j]){
                s.push(i*w+j);
            }
            while(!s.empty()){
                int now = s.top();
                s.pop();

                if(shirabeta[now/w][now%w]){
                    continue;
                }

                shirabeta[now/w][now%w] = true;

                for(int k=0;k<4;k++){
                    int ni = now/w + di[k];
                    int nj = now%w + dj[k];
                    if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                        if(!shirabeta[ni][nj] && map[ni][nj] == '.'){
                            s.push(ni*w + nj);
                            unite(now, ni*w + nj);
                        }
                    }
                }
            }
        }
    }

    int n;
    cin >> n;
    if(find(0) == find(ti*w+tj)){
        cout << 0 << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        map[y][x] = '.';
        for(int j=0;j<4;j++){
            int ni = y + di[j];
            int nj = x + dj[j];
            if(ni >= 0 && ni < h && nj >= 0 && nj < w){
                if(map[ni][nj] == '.'){
                    unite(y*w+x, ni*w+nj);
                }
            }
        }
        if(find(0) == find(ti*w+tj)){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
