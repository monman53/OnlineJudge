#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    bool data[500][500];
    int sumb[1000];
    int check[1000];
    scanf("%d%d",&n,&k);    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            data[i][j] = false;
        }
        sumb[i*2] = sumb[i*2 + 1] = 0;
        check[i*2] = check[i*2 + 1] = false;
    }
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        data[a-1][b-1] = true;
        sumb[(a-1)*2]++;
        check[(a-1)*2] = true;
        sumb[(b-1)*2+1]++;
        check[(a-1)*2] = true;
    }
    int count = 0;
    while(1){
        bool flag = true;
        int max=0,maxl;
        for(int i=0;i<n*2;i++){
            if(check[i]){
                int sum = 0;
                for(int j=0;j<n;j++){
                    if(i%2 == 0){
                        if(data[
                    }
                }
            }
        }
        if(flag) break;
    }

    return 0;
}
