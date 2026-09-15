#include "../header.cpp"

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
