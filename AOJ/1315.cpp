#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        map<string, int> log;
        map<string, int> time;
        map<string, int>::iterator time_it;
        set<string> list;
        set<string>::iterator list_it;
        
        bool goddess = false;
        for(int i=0;i<n;i++){
            string date,ntime,id;
            char io;
            cin >> date >> ntime >> io >> id;

            int inttime = int(ntime[0] - '0')*600 + int(ntime[1] - '0')*60 + int(ntime[3] - '0')*10 + int(ntime[4] - '0');
            
            if(io == 'I'){
                if(id == "000"){
                    goddess = true;
                    list_it = list.begin();
                    while(list_it != list.end()){
                        log[*list_it] = inttime;
                        list_it++;
                    }
                }else{
                    if(time.find(id) == time.end()){
                        time[id] = 0;
                    }
                    list.insert(id);
                    log[id] = inttime;
                }
            }
            if(io == 'O'){
                if(id == "000"){
                    list_it = list.begin();
                    while(list_it != list.end()){
                        time[*list_it] += inttime - log[*list_it];
                        list_it++;
                    }
                    goddess = false;
                }else{
                    if(goddess){
                        time[id] += inttime - log[id];
                    }
                    list.erase(id);
                    log.erase(id);
                } 
            }
        }
        time_it = time.begin();
        int max = 0;
        while(time_it != time.end()){
            if((*time_it).second >= max){
                max = (*time_it).second;
            }
            time_it++;
        }
        cout << max << '\n';
    }
    return 0;
}
