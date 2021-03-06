#include <iostream>
#define INF 999999999
using namespace std;

int main(){
    int n,a,b;
    int effort[101];
    int count[101];
    bool direct[101][101];
    int from[101][101];

    cin >> n >> a >> b;
    for(int i=1;i<101;i++){
        count[i] = 0;
    }
    for(int i=1;i<=n;i++){
        effort[i] = INF;
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int to;
            cin >> to;
            from[to][count[to]] = i;
            if(j==0){
                direct[to][count[to]] = true;
            }else{
                direct[to][count[to]] = false;
            }
            count[to]++;
        }
    }

    effort[a] = 0;
    while(1){
        bool changed = false;
        for(int i=1;i<=n;i++){
            //cout << "kita1";
            for(int j=0;j<count[i];j++){
                //cout << "KITA2";
                int cost = effort[from[i][j]];
                if(!direct[i][j]){
                    cost++;
                }
                //cout << cost;
                if(cost < effort[i]){
                    effort[i] = cost;
                    changed = true;
                }
            }
        }
        if(!changed) break;
    }
    if(effort[b] == INF){
        cout << -1 << '\n';
    }else{
        cout << effort[b] << '\n';
    }
    return 0;
}
