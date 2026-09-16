#include "../header.cpp"

// 二次配列flip
template<typename T>vector<vector<T>> flip(vector<vector<T>>&s){
    int h=s.size(),w=s[0].size();
    vector<vector<T>> res(w);
    rep(i,h)rep(j,w)res[j].pushback(s[i][j]);
    return res;
}
// string ver
vector<string> flip(vector<string>&s){
    int h=s.size(),w=s[0].size();
    vector<string> res(w);
    rep(i,h)rep(j,w)res[j]+=s[i][j];
    return res;
}
