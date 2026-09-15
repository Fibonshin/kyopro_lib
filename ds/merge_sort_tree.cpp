#include "../header.cpp"

// https://atcoder.jp/contests/abc339/submissions/50038712
struct SEG{
    int n;
    vector<vector<int>> dat;
    vector<vector<ll>> acc;
    SEG(vector<int> a):n(__bit_ceil(a.size())),dat(2*n),acc(2*n){
        rep(i,a.size())dat[i+n].push_back(a[i]);
        for(int i=n-1;i>=0;i--){
            for(int j:dat[2*i])dat[i].push_back(j);
            for(int j:dat[2*i+1])dat[i].push_back(j);
            sort(dat[i].begin(),dat[i].end());
        }
        rep(i,2*n){
            acc[i].resize(dat[i].size()+1);
            rep(j,dat[i].size())acc[i][j+1]=acc[i][j]+dat[i][j];
        }
    }

    ll prod(int l,int r,int x){return prod_sub(l,r,1,0,n,x);}

    ll prod_sub(int l,int r,int k,int a,int b,int x){
        if(b<=l || r<=a)return 0;
        if(l<=a && b<=r){
            return acc[k][upper_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin()];
        }
        return prod_sub(l,r,2*k,a,(a+b)/2,x)+prod_sub(l,r,2*k+1,(a+b)/2,b,x);
    }
};
