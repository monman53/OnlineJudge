#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

int perm[10];
int data[10];
bool used[10];
int mmin=9999999;

void permutate(int pos,int n){
    if(pos == n){
        /*for(int i=0;i<n;i++){
            printf("%d",perm[i]);
        }
        */
        for(int i=1;i<n-1;i++){
            //printf("%d",perm[i]);
            int a=0,b=0;
            bool ok=true;
            for(int j=0,ten=1;j<i;j++,ten*=10){
                if(perm[j] == 0 && j==i-1 && j!=0){
                    ok = false;
                    break;
                }else{
                    a += perm[j]*ten;
                }
            }

            for(int j=i,ten=1;j<n;j++,ten*=10){
                if(perm[j] == 0 && j==n-1 && j!=0){
                    ok = false;
                    break;
                }else{
                    b += perm[j]*ten;
                }
            }

            if(abs(a-b) < mmin && ok){
                mmin = abs(a-b);
            }
        }
        //printf(" %d %d\n",pos,n);
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i] && !(pos==n-1 && i>=n/2)){
            perm[pos] = data[i];
            used[i] = true;
            permutate(pos+1,n);
            used[i] = false;
        }
    }
}

int main(){
    int n;
    
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        mmin = 999999;
        char buf[22];
        for(int j=0;j<10;j++){
            used[i] = false;
        }
        fgets(buf,25,stdin);
        int k=0;
        for(int j=0;buf[j];j++){
            if(buf[j] != ' ' && buf[j] != '\n'){
                data[k] = buf[j] - '0';
                //printf("%d",data[k]);
                k++;
            }
        }
        permutate(0,k);
        printf("%d\n",mmin);
    }

    return 0;
}
