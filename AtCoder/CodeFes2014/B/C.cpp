#include <iostream>
#include <string>
#include <set>
using namespace std;

int c1[26],c2[26],c3[26];
set<char> list;
set<char>::iterator list_it;
int mozisu;

bool calc(int count1,int ccount2){
    char now = int(*list_it);
    if(count1 == mozisu && count2 == mozisu){
        return true;
    }
    if(c1[now] + c2[now] < c3[now]){
        return false;
    }
    for(
}

int main(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    for(int i=0;i<26;i++){
        c1[i] = c2[i] = c3[i] = 0;
    }
    for(int i=0;i<s1.size();i++){
        c1[int(s1[i])]++;
        c2[int(s2[i])]++;
        c3[int(s3[i])]++;
        list.insert(s3[i]);
    }
    calc(0,0);
    list_it = list.begin();

    return 0;
}
