#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main(){
    char data[10][20];
    int di[8] = {0,-1,-1,-1,0,1,1,1};
    int dj[8] = {1,1,0,-1,-1,-1,0,1}; 

    while(1){
        int h,w;
        cin >> h >> w;
        if(h == 0 && w == 0) break;

        map<string, int> mapp;
        map<string, int>::iterator map_it;

        for(int i=0;i<h;i++){
            string s;
            cin >> s;
            for(int j=0;j<w;j++){
                data[i][j] = s[j];
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                for(int k=0;k<8;k++){
                    int nowi = i;
                    int nowj = j;
                    string s="";
                    bool end = false;
                    while(1){
                        //cout << '(' << nowi << ',' << nowj << ")\n";
                        s += data[nowi][nowj];
                        if(end) break;
                        nowi += di[k];
                        nowj += dj[k];
                        if(nowi == -1) nowi = h-1;
                        if(nowj == -1) nowj = w-1;
                        if(nowi == h) nowi = 0;
                        if(nowj == w) nowj = 0;
                        if(nowi == i && nowj == j) end=true;
                    }
                    if(mapp.find(s) == mapp.end()){
                        mapp[s] = 1;
                    }else{
                        mapp[s] += 1;
                    }
                }
            }
        }

        map_it = mapp.begin();
        while(map_it != mapp.end()){
            if((*map_it).second > 1){
                cout << (*map_it).first << '\n';
            }
            map_it++;
        }

    }
    return 0;
}
