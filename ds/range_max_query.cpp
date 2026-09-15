#include "../header.cpp"

// Range Max Query
struct RMQ{
    int n;
    int e=0;
    vector<int> dat;
    RMQ(vector<int> a):n(__bit_ceil(a.size())),dat(2*n,e){
        rep(i,a.size())dat[i+n]=a[i];
        for(int i=n-1;i>=0;i--)dat[i]=max(dat[2*i],dat[2*i+1]);
    }

    void set(int p,int x){
        p=p+n;
        dat[p]=x;
        while (p/=2)dat[p]=max(dat[2*p],dat[2*p+1]);        
    }

    int prod(int l,int r){return prod_sub(l,r,1,0,n);}

    int prod_sub(int l,int r,int k,int a,int b){
        if(b<=l || r<=a)return e;
        if(l<=a && b<=r)return dat[k];
        return max(prod_sub(l,r,2*k,a,(a+b)/2),prod_sub(l,r,2*k+1,(a+b)/2,b));
    }
};
