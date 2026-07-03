#include "header.cpp"
 
// 回文判定
bool is_palindrome(string s){
    int n=s.size();
    rep(i,n/2)if(s[i]!=s[n-i-1])return 0;
    return 1;
}

// 二次配列回転
// string ver → https://atcoder.jp/contests/abc218/submissions/49616879
template<typename T>vector<vector<T>> rot(vector<vector<T>>&s,int deg=1){
    rep(i,deg-1)s=rot(s);
    int h=s.size(),w=s[0].size();
    vector res(w,vector<T>(h));
    rep(i,h)rep(j,w)res[j][h-i-1]=s[i][j];
    return res;
}

// 配列の余白をカット → https://atcoder.jp/contests/abc218/submissions/49616879


// 床関数と天井関数
ll floor(ll x,ll m){return (x-(x%m+m)%m)/m;}
ll ceil(ll x,ll m){return (x+(-x%m+m)%m)/m;}

// sorted
template<typename T> vector<T> sorted(vector<T> x){
    sort(x.begin(),x.end());
    return x;
}

// 要素が[0,mx]の数列の転倒数
ll inversion_number(vector<int> x,int mx){
    ll res=0;
    fenwick_tree<int> fw(mx+1);
    for(int i:x){
        res+=fw.sum(i+1,mx+1);
        fw.add(i,1);
    }
    return res;
}

// ポテンシャルつきUnionFind
// 座標平面ver → https://atcoder.jp/contests/adt_all_20240110_1/submissions/49196757
struct WeightedUnionFind{
    vector<ll> par,siz,ws;
    WeightedUnionFind(int n):par(n,-1),siz(n,1),ws(n,0){}
    
    pair<int,ll> root(int a){
        ll res=0;
        while (par[a]!=-1)res+=ws[a],a=par[a];
        return {a,res};
    }

    void unite(int a,int b,ll w){
        auto[pa,wa]=root(a);
        auto[pb,wb]=root(b);
        if(siz[pa]>siz[pb])swap(pa,pb),swap(wa,wb),w=-w;
        par[pa]=pb;
        siz[pb]+=siz[pa];
        ws[pa]=w-wa+wb;
    }

    ll diff(int a,int b){return root(a).second-root(b).second;}
    bool same(int a,int b){return root(a).first==root(b).first;}
};
