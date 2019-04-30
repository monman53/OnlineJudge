#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(){
    ll ans=0;
    int n;
    int data[20000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }

    while(n>1){
        int ml1=0,ml2=1;
        if(data[ml2] < data[ml1]){
            swap(ml2,ml1);
        }
        for(int i=2;i<n;i++){
            if(data[i] < data[ml1]){
                ml2 = ml1;
                ml1 = i;
            }else if(data[i] < data[ml2]){
                ml2 = i;
            }
        }

        ans += data[ml1]+data[ml2];
        if(ml1 == n-1){
            swap(ml1,ml2);
        }
        data[ml1] = data[ml1]+data[ml2];
        data[ml2] = data[n-1];
        n--;
    }

    printf("%lld\n",ans);

    return 0;
}
