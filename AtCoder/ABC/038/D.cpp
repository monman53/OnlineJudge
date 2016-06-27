#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
    int w;
    int h;
    int max;
};

int main(){
    int n;
    cin >> n;
    Box box[n];
    for(int i=0;i<n;i++){
        Box b;
        cin >> b.w >> b.h;
        b.max = 1;
        box[i] = b;
    }
    sort(box, box+n, [](const Box& a, const Box& b){
            return a.w == b.w ? a.h < b.h : a.w < b.w;
            });

    int ans = 1;
    for(int i=0;i<n;i++){
        //cout << box[i].w << " " << box[i].h << endl;
        for(int j=i+1;j<n;j++){
            if(box[i].w < box[j].w && box[i].h < box[j].h){
                box[j].max = max(box[j].max, box[i].max + 1);
                ans = max(ans, box[j].max);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
