#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int n,t;
    vector<pair<int,int> > data;
    int lastend=0;
    int count=0;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        data.push_back(pair<int,int>(a,b));
    }
    sort(data.begin(),data.end());
    int datasize = data.size();
    for(int i=0;i<datasize;){
        int max=-1;
        for(;i<datasize;i++){
            int from=data[i].first;
            int to=data[i].second;
            if(to > max && from <= lastend+1){
                max = to;
                if(max == t){
                    count++;
                }
                //printf("%d\n",max);
            }
            if(from >= lastend+2 && max <= lastend){
                printf("-1\n");
                return 0;
            }else if(from >= lastend+2){
                lastend = max;
                //printf("kita%d %d %d max%d\n",i,from,to,max);
                count++;
                i--;
            }
        }
        //printf("%d %d\n",data[i].first,data[i].second);
    }
    printf("%d\n",count);
    return 0;
}
