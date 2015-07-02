#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Book{
  string title, author, date;
};

int main(){
  int n, q;
  cin >> n;
  vector<Book> book(n);
  for(int i=0;i<n;i++){
    cin >> book[i].title >> book[i].author >> book[i].date;
  }

  cin >> q;
  string q_title, q_author, q_date_from, q_date_to;
  for(int i=0;i<q;i++){
    cin >> q_title >> q_author >> q_date_from >> q_date_to;
  
    for(int j=0;j<n;j++){
      if(book[j].title.find(q_title) == string::npos && q_title != "*"){
        continue;
      }
      if(book[j].author.find(q_author) == string::npos && q_author != "*"){
        continue;
      }
      if(book[j].date < q_date_from && q_date_from != "*"){
        continue;
      }
      if(book[j].date > q_date_to && q_date_to != "*"){
        continue;
      }
      cout << book[j].title << '\n';
    }

    if(i != q-1){
      cout << '\n';
    }
  }
}
