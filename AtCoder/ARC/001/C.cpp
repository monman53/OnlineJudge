#include <iostream>
using namespace std;

char c[8][8];

bool free(int ci, int cj) {
    for(int i=1;i<8;i++){
        if(cj+i<8)   if(c[ci][cj+i] == 'Q') return false;
        if(ci-i>=0)  if(c[ci-i][cj] == 'Q') return false;
        if(cj-i>=0)  if(c[ci][cj-i] == 'Q') return false;
        if(ci+i<8)   if(c[ci+i][cj] == 'Q') return false;
        if(ci-i>=0 && cj+i<8)   if(c[ci-i][cj+i] == 'Q') return false;
        if(ci-i>=0 && cj-i>=0)  if(c[ci-i][cj-i] == 'Q') return false;
        if(ci+i<8 && cj-i>=0)   if(c[ci+i][cj-i] == 'Q') return false;
        if(ci+i<8 && cj+i<8)    if(c[ci+i][cj+i] == 'Q') return false;
    }
    return true;
}

bool check() {
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(c[i][j] == 'Q'){
                if(!free(i, j)) return false;
            }
        }
    }
    return true;
}

bool solve(int n) {

    if(n == 0) {
        return check();
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(c[i][j] == '.' && free(i, j)){
                c[i][j] = 'Q';
                if(solve(n-1)){
                    return true;
                }
                c[i][j] = '.';
            }
        }
    }

    return false;
}

int main() {

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> c[i][j];
        }
    }

    if(solve(5)){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout << c[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "No Answer" << endl;
    }

    return 0;
}
