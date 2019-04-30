#include <cstdio>
#include <iostream>

int main(){
    int n;
    char cow[2001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&cow[i]);
    }

    int a=0,b=n-1,count=0;
    while(a<=b){
        bool left = false;
        for(int i=0;a+i<=b;i++){
            if(cow[a+i] < cow[b-i]){
                left = true;
                break;
            }else if(cow[a+i] > cow[b-i]){
                left = false;
                break;
            }
        }
        if(left){
            putchar(cow[a++]);
        }else{
            putchar(cow[b--]);
        }
        count++;
        if(count%80 == 0){
            printf("\n");
        }
    }
    printf("\n");
    return 0;
} 
