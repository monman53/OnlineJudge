#include <iostream>
#include <queue>
#define INF 99999999
using namespace std;

struct Ninja{
    int tower,step,i;
    Ninja(int a,int b,int c){
        tower = a;
        step = b;
        i =c;
    }
    Ninja(){
    }
};

int main(){
    while(1){
        int n;
        int data[2][100];
        bool kita[2][100];
        int min=INF;
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> data[i][j];
                kita[i][j] = false;
            }
        }
        queue<Ninja> que;
        que.push(Ninja(0,0,0));
        que.push(Ninja(1,0,0));
        while(que.size()){
            Ninja cNinja = que.front();
            int ctower = cNinja.tower;
            int cstep = cNinja.step;
            int ci = cNinja.i;
            que.pop();
            if(kita[ctower][ci]){
                continue;
            }
            if(ci==n-1 && data[ctower][ci]!=2){
                min = cstep;
                break;
            }
            if(data[ctower][ci]==0){
                kita[ctower][ci]=true;
                for(int i=0;i<=2;i++){
                    int ni = ci+i;
                    if(ni < n){
                        que.push(Ninja(1-ctower,cstep+1,ni));
                    }
                }
                continue;
            }
            if(data[ctower][ci]==1){
                int m=0;
                while(data[ctower][ci + m]==1){
                    kita[ctower][ci + m] = true;
                    if(ci + m == n-1){
                        min = cstep;
                    }
                    m++;
                }
                if(min != INF){
                    break;
                }
                for(int i=0;i<=2;i++){
                    int ni = ci+m-1+i;
                    if(ni < n){
                        que.push(Ninja(1-ctower,cstep+1,ni));
                    }
                }
                continue;
            }
            if(data[ctower][ci]==2){
                int m=0;
                while(data[ctower][ci-m]==2){
                    kita[ctower][ci-m]=true;
                    m++;
                }
                for(int i=0;i<=2;i++){
                    int ni = ci-m+i;
                    if(ni < n){
                        que.push(Ninja(1-ctower,cstep+1,ni));
                    }
                }
                continue;
            }
        }
        if(min == INF){
            cout << "NA\n";
        }else{
            cout << min << '\n';
        }
    }
    return 0;
}
