#include "../header.cpp"

// Manacher's Algorithm
vector<int> Manacher(string s){

    int siz=s.size();
    vector<int> res(siz);
    int i=0,j=0;
    while (i<siz){
        while(i-j>=0 && i+j<siz && s[i-j]==s[i+j])j++;
        res[i]=j;
        int k=1;
        while (i-k>=0 && k+res[i-k]<j)res[i+k]=res[i-k],k++;
        i+=k,j-=k;
    }
    return res;
}

