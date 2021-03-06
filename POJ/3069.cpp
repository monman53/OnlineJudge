#include <cstdio>

int main(){
    int r,n;
    bool data[1001];
    while(1){
        scanf("%d%d",&r,&n);
        if(r== -1){
            break;
        }
        int count=0;
        for(int i=0;i<1001;i++){
            data[i] = false;
        }
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            data[x] = true;
        }
        for(int i=0;i<1001;i++){
            if(data[i]){
                for(int j=r;j>=0;j--){
                    if(i+j<1001){
                        if(data[i+j]){
                            count++;
                            i=i+j+r;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
