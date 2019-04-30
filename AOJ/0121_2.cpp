#include <iostream>
#define INF 999999999
using namespace std;

int di[5] = {1,-1,4,-4,0};
int bi[5] = {1,0,3,2,4};
int data[8];
int mmin;

bool check(int i, int d){
    int ni = i + di[d];
    if(ni < 0 || ni > 7 || (i == 3 && d == 0) || (i == 4 && d == 1)) return false;
    else return true;
}

void calc(int i,int step, int d){
    //cout << step << ' ';
    for(int j=0;j<8;j++){
        if(data[j] != j) break;
        if(j == 7 && step < mmin){
            cout << step;
            mmin = step;
            return;
        }
    }
    for(int j=0;j<4;j++){
        if(j != bi[d] && check(i,j)){
            int ni = i+di[j];
            data[i] = data[ni];data[ni] = 0;
            calc(ni, step+1, j);
            data[ni] = data[i];data[i] = 0;
        }
    }
    return;
}


int main(){
    while(1){
        bool end=false;
        int si;
        
        for(int i=0;i<8;i++){
            cin >> data[i];
            if(cin.eof()){
                end = true;
                break;
            }
            if(data[i] == 0) si = i;
        }
        if(end) break;
        
        mmin = INF;
        calc(si,0,4);
        cout << mmin << '\n';
    }
    return 0;
}
