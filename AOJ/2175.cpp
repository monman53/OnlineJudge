#include <iostream>
using namespace std;

struct Data{
  char suit;
  int rank;
};

int main(){
  char trump;
  while(1){
    cin >> trump;
    if(trump == '#') break;
    
    Data data[4][13];
    string s;

    for(int i=0;i<4;i++){
      for(int j=0;j<13;j++){
        cin >> s;
        data[i][j].suit = s[1];
        if(s[0] == 'A') data[i][j].rank = 14;
        if(s[0] == 'K') data[i][j].rank = 13;
        if(s[0] == 'Q') data[i][j].rank = 12;
        if(s[0] == 'J') data[i][j].rank = 11; 
        if(s[0] == 'T') data[i][j].rank = 10;
        if(s[0] >= '2' && s[0] <= '9') data[i][j].rank = s[0] - '0';
      }
    }
    
    int score[2] = {0, 0};
    int winner = 0;

    for(int i=0;i<13;i++){
      for(int j=0;j<4;j++){
        if(j != winner){
          if((data[j][i].suit == data[winner][i].suit && data[j][i].rank > data[winner][i].rank) ||
              data[winner][i].suit != trump && data[j][i].suit == trump){
            winner = j;
          }
        }
      }
      score[winner%2]++;
    }

    if(score[0] > score[1]){
      cout << "NS " << score[0] << '\n';
    }else{
      cout << "EW " << score[1] << '\n';
    }
  }
  return 0;
}
