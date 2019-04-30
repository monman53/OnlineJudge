#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,pair<int,int> > Q;

struct Spr{
    int x;
    int y;
    Spr(){
        x = 0;
        y = 0;
    }
    Spr(int a,int b){
        x = a;y = b;
    }
};

int jumpx[12] = {2,2,1,0,-1,-2,-2,-2,-1, 0, 1, 2};
int jumpy[12] = {0,1,2,2, 2, 1, 0,-1,-2,-2,-2,-1};

int main(){
    int firstx,firsty;
    int n;
    Spr spr[10];
    while(1){
        cin >> firstx >> firsty;
        if(firstx == 0 && firsty == 0){
            break;
        }
        cin >> n;
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            spr[i] = Spr(x,y);
        }
        queue<Q> que;
        bool goalf=false;
        for(int i=0;i<12;i++){
            int nx = firstx + jumpx[i];
            int ny = firsty + jumpy[i];
            if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10){ 
                que.push(Q(0,pair<int,int>(nx,ny)));
            }
        }
        while(que.size()){
            Q cq = que.front();
            que.pop();
            int cx = cq.second.first;
            int cy = cq.second.second;
            int csx = spr[cq.first].x;
            int csy = spr[cq.first].y;
            if(!(cx >= csx-1 && cx <= csx+1 && cy >= csy-1 && cy <= csy+1)){
                continue;
            }else if(cq.first == n-1){
                goalf = true;
                break;
            }
            //cout << cq.first << "( " << cx << " " << cy << " )\n";
            for(int i=0;i<12;i++){
                int nx = cx + jumpx[i];
                int ny = cy + jumpy[i];
                if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10){ 
                    que.push(Q(cq.first+1,pair<int,int>(nx,ny)));
                }
            }
        }
        if(goalf){
            cout << "OK\n";
        }else{
            cout << "NA\n";
        }
    }
    return 0;
}
