#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

int main() {
    //int kita[5][4];
    //for(int i=0;i<5;i++){
        //for(int j=0;j<4;j++){
            //kita[i][j] = 0;
        //}
    //}

    //queue<pair<P, vector<P>>> q;
    //q.push({P{0, 0}, {}});
    //while(!q.empty()){
        //auto p = q.front().first;
        //auto v = q.front().second;
        //v.push_back(p);
        //q.pop();

        //if(kita[p.first][p.second] == 1){
            //continue;
        //}
        //int a = p.first;
        //int b = p.second;
        //kita[a][b] = 1;

        //if(a == 2 || b == 2){
            //for(auto ans : v){
                //cout << "(" << ans.first << "," << ans.second << ")";
            //}
            //cout << endl;
            //break;
        //}

        //q.push({{4, b}, v});
        //q.push({{a, 3}, v});
        //q.push({{0, b}, v});
        //q.push({{a, 0}, v});
        //q.push({{max(0, a-(3-b)), min(3, b+a)}, v});
        //q.push({{min(4, a+b), max(0, b-(4-a))}, v});
    //}


    pair<int, int> dp[2][5][4];
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            dp[0][i][j] = dp[1][i][j] = {-1, -1};
        }
    }

    dp[0][0][0] = {0, 0};

    for(int i=0;;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<4;k++){
                if(dp[i%2][j][k] == P{-1, -1}) continue;

            }
        }
    }

    return 0;
}
