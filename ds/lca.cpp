#include "../header.cpp"

// gは木
// https://atcoder.jp/contests/abc014/submissions/79330327
// https://judge.yosupo.jp/submission/403790

struct LCA{
	vector<vector<int>> g;
	int n;
	vector<int> d,p;
	vector<vector<int>> dp;
	int log=30;
	LCA(vector<vector<int>>&g_):g(g_){
		n=g.size();
		d.resize(n);
		p.resize(n);
		dp.assign(log,vector<int>(n));
		auto dfs=[&](auto f,int x,int px)->void {
			for(int nx:g[x])if(nx!=px){
				d[nx]=d[x]+1;
				p[nx]=x;
				f(f,nx,x);
			}
		};
		dfs(dfs,0,0);
		rep(i,n)dp[0][i]=p[i];
		rep(i,log-1)rep(j,n)dp[i+1][j]=dp[i][dp[i][j]];
	}
	int get(int u,int v){
		if(d[u]<d[v])swap(u,v);
		rep(i,log)if((d[u]-d[v])&1<<i){
			u=dp[i][u];
		}
		if(u==v)return u;
		for(int i=log-1;i>=0;i--){
			if(dp[i][u]!=dp[i][v]){
				u=dp[i][u];
				v=dp[i][v];
			}
		}
		return dp[0][u];
	}
	int dist(int u,int v){
		int c=get(u,v);
		return d[u]+d[v]-2*d[c];
	}
};
