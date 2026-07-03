#include "header.cpp"
 
// N頂点M辺の最小全域木の重みの最小。uとvの無向辺で重みがc。非連結な時INF。
ll mst(int n,int m,vector<int> u,vector<int> v,vector<int> c){
    ll res=0;
    dsu uf(n);
    vector<TUP> es;
    rep(i,m)es.emplace_back(c[i],u[i],v[i]);
    sort(es.begin(),es.end());
    for(auto[nc,nu,nv]:es){
        if(!uf.same(nu,nv)){
            uf.merge(nu,nv);
            res+=nc;
        }
    }
    return uf.size(0)==n?res:inf;
}
