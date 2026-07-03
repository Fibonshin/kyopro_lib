#include "header.cpp"
 
// Z algorithm O(|S|)
vector<int> z_algo(string&s){
    int n= s.size();
    vector<int> z(n+1);
    z[0]=n;
    int i=1,j=0;
    while (i < n){
        while (i+j < n && s[i+j]==s[j])j++;
        z[i]=j;
        if(j==0){
            i++;
            continue;
        }
        int k=1;
        while (z[k] < j-k){
            z[i+k]=z[k];
            k++;
        }
        i+=k;
        j-=k;
    }
    return z;
}

// RunLengthEncoding O(N)
vector<pair<char,int>> RunLengthEncoding(string&x){
    vector<pair<char,int>> res;
    res.emplace_back(x[0],0);
    for(char c:x)if(res.back().first==c)res.back().second++;
    else res.emplace_back(c,1);
    return res;
};

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

// RollingHash sの中にtが何回出現するかO(|S|)
// https://yukicoder.me/submissions/941850 mod 2^64-1。速い。
int roliha(string s,string t){
    int b1=1009,b2=1033;
    int sl=s.size(),tl=t.size();
    if(tl > sl)return 0;
    mint sh1=0,th1=0,d1=1;
    mint sh2=0,th2=0,d2=1;
    rep(i,tl)d1*=b1,sh1*=b1,th1*=b1,sh1+=s[i],th1+=t[i];
    rep(i,tl)d2*=b2,sh2*=b2,th2*=b2,sh2+=s[i],th2+=t[i];
    int res=(sh1==th1 && sh2==th2);
    for(int l=0,r=tl;r<sl;l++,r++){
        sh1=sh1*b1-d1*s[l]+s[r];
        sh2=sh2*b2-d2*s[l]+s[r];
        res+=(sh1==th1 && sh2==th2);
    }
    return res;
}
