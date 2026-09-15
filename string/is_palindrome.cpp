#include "../header.cpp"

// 回文判定
bool is_palindrome(string s){
    int n=s.size();
    rep(i,n/2)if(s[i]!=s[n-i-1])return 0;
    return 1;
}

