#include "../header.cpp"

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
