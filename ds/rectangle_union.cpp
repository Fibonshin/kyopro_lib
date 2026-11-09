#include "header.hpp"
// Area of Union of Rectangles
// require: g++20
// https://judge.yosupo.jp/submission/416002
// https://atcoder.jp/contests/abc449/submissions/80736661

struct RectangleUnion{
	vector<tuple<int,int,int,int>> query;
	int w=0;
	void add(int l,int d,int r,int u){
		assert(d<u && l<r);
		chmax(w,r);
		query.emplace_back(d,l,r,1);
		query.emplace_back(u,l,r,-1);
	}
	ll area(){
		sort(query.begin(),query.end());
		map<int,int> mp;
		for(auto[r,cl,cr,d]:query)mp[cl],mp[cr];
		mp[0],mp[w];
		{
			int i=0;
			for(auto&[k,v]:mp)v=i++;
		}
		int m=mp.size();
		vector<int> ws(m);
		{
			auto it=mp.begin();
			rep(i,m-1){
				ws[i]-=it->first;
				it++;
				ws[i]+=it->first;
			}
		}
		for(auto&[r,cl,cr,d]:query)cl=mp[cl],cr=mp[cr];
		struct S{
			int x;
			int cnt;
		};
		auto op=[](S a,S b){
			S c;
			c.x=min(a.x,b.x);
			c.cnt=0;
			if(a.x==c.x)c.cnt+=a.cnt;
			if(b.x==c.x)c.cnt+=b.cnt;
			return c;
		};
		auto e=[](){return S{(int)1e9,0};};
		auto mapping=[](int f,S x){x.x+=f;return x;};
		auto composition=[](int f,int g){return f+g;};
		auto id=[](){return 0;};
		vector<S> v(m);
		rep(i,m)v[i]={0,ws[i]};
		lazy_segtree<S,op,e,int,mapping,composition,id> seg(v);
		int i=0;
		ll ans=0;
		for(auto[r,cl,cr,d]:query){
			S pr=seg.all_prod();
			ans+=ll(w-pr.cnt)*(r-i);
			seg.apply(cl,cr,d);
			i=r;
		}
		return ans;
	}
};
