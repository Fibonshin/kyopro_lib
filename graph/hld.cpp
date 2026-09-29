#include "header.hpp"
// https://judge.yosupo.jp/submission/406748
// https://judge.yosupo.jp/submission/406749
// https://atcoder.jp/contests/abc014/submissions/79611366

struct hld{
	int n;
	vector<int> vertex,id,head,par,dep;
	hld(vector<vector<int>> g){
		n=g.size();
		id.resize(n);
		head.resize(n);
		par.resize(n);
		dep.resize(n);
		{
			auto f=[&](auto f,int x,int px)->int{
				int cnt=1,mx=0;
				rep(i,g[x].size()){
					int nx=g[x][i];
					if(nx==px)continue;
					int s=f(f,nx,x);
					cnt+=s;
					if(chmax(mx,s))swap(g[x][0],g[x][i]);
				}
				return cnt;
			};
			f(f,0,0);
		}
		{
			auto f=[&](auto f,int x,int px)->void{
				id[x]=vertex.size();
				vertex.push_back(x);
				for(int nx:g[x])if(px!=nx){
					par[nx]=x;
					dep[nx]=dep[x]+1;
					head[nx]=(nx==g[x][0]?head[x]:nx);
					f(f,nx,x);
				}
			};
			f(f,0,0);
		}
	}
	int lca(int u,int v){
		while(head[u]!=head[v]){
			if(id[u]>id[v])u=par[head[u]];
			else v=par[head[v]];
		}
		return id[u]<id[v]?u:v;
	}
	int dist(int u,int v){
		int c=lca(u,v);
		return dep[u]+dep[v]-2*dep[c];
	}
	int level_ancestor(int u,int d){
		if(dep[u]<d)return -1;
		while(dep[head[u]]>d){
			u=par[head[u]];
		}
		return vertex[id[u]-(dep[u]-d)];
	}
	int jump_up(int u,int steps){
		return level_ancestor(u,dep[u]-steps);
	}
	int jump(int u,int v,int steps){
		int c=lca(u,v);
		int uc=dep[u]-dep[c];
		int vc=dep[v]-dep[c];
		if(steps < uc)return jump_up(u,steps);
		else if(steps-uc<=vc)return jump_up(v,uc+vc-steps);
		else return -1;
	}
};
