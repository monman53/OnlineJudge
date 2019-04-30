#include <iostream>
#include <string>
using namespace std;

int main(){
    int T,d,sum,size,size2;
    bool c;
    string s;
    int data[10000];
    cin >> T;
    for(int i=0;i<T;i++){
        sum = 0;
        cin >> s;
        //cout <<"s" <<  s << ": ";
        size2 = size = s.size();
        for(int i=0;i<size;i++){
            data[i] = s[size-i-1]-'0';
        }
        if(s.size()%3==1){
            data[size] = 0;
            data[size+1] = 0;
            size2 += 2;
        }else if(s.size()%3==2){
            data[size] = 0;
            size2 += 1;
        }
        c=true;
        for(int j=0;j<size2/3;j++){
            d = (data[j*3]) + (data[j*3+1])*10 + (data[j*3+2])*100;
            if(c){
                //cout << "d=" << d << "\n";
                sum += d;
            }else{
                //cout << "d=" << d << "\n";
                sum -= d;
            }
            c = !c;
            if(data[j*3+0] == 7 || data[j*3+1] == 7 || data[j*3+2] == 7){
                sum = 0;
                //cout << "kita\n";
                break;
            }
        }
        //cout << "sum " << sum << " : ";
        if(sum%7==0){
            cout << "Baka\n";
        }else{
            for(int j=0;j<size;j++){
                cout << s[j];
            }
            cout << '\n';
        }
    }
    return 0;
}
