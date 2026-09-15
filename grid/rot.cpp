#include "../header.cpp"

// 二次配列回転
// string ver → https://atcoder.jp/contests/abc218/submissions/49616879
template<typename T>vector<vector<T>> rot(vector<vector<T>>&s,int deg=1){
    rep(i,deg-1)s=rot(s);
    int h=s.size(),w=s[0].size();
    vector res(w,vector<T>(h));
    rep(i,h)rep(j,w)res[j][h-i-1]=s[i][j];
    return res;
}

