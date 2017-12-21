// {{{
// 文字列の分解
// ABC033
vector<string> split(string &s, char c) {
    vector<string> ret;
    int b = 0;
    int n = s.size();
    int i;
    for(i=0;i<n;i++){
        if(s[i] == c){
            ret.push_back(s.substr(b, i-b));
            b = i+1;
        }
    }
    ret.push_back(s.substr(b, i-b));
    return ret;
}
// }}}
