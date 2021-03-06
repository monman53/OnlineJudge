#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    char ch[1000];
    int n;
    int hako[1001][1001];
    for(int i=0;i<1001;i++){
        hako[0][i] = hako[i][0] = 0;
    }
    while(1){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        int max=0;
        for(int i=1;i<=n;i++){
            scanf("%s",ch);
            for(int j=1;j<=n;j++){
                if(ch[j-1]!='*'){
                    hako[i][j] = min(hako[i-1][j-1],min(hako[i-1][j],hako[i][j-1])) + 1;
                    if(hako[i][j] > max){
                        max = hako[i][j];
                    }
                }else{
                    hako[i][j] = 0;
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
