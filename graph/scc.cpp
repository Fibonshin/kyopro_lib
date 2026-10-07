#include <header.hpp>
// https://atcoder.jp/contests/practice2/submissions/79848607
// https://atcoder.jp/contests/abc478/submissions/79848629

vector<vector<int>> scc(vector<vector<int>>&g){
	int n=g.size();
	vector<vector<int>> rg(n);
	rep(u,n)for(int v:g[u])rg[v].push_back(u);
	stack<int> st;
	{
		vector<int> vis(n);
		auto f=[&](auto f,int u)->void{
			vis[u]=1;
			for(int v:g[u])if(!vis[v])f(f,v);
			st.push(u);
		};
		rep(u,n)if(!vis[u])f(f,u);
	}
	vector<vector<int>> res;
	{
		vector<int> vis(n);
		auto f=[&](auto f,int u)->void{
			vis[u]=1;
			res.back().push_back(u);
			for(int v:rg[u])if(!vis[v])f(f,v);
		};
		while(!st.empty()){
			res.emplace_back(0);
			f(f,st.top());
			while(!st.empty() && vis[st.top()])st.pop();
		}
	}
	return res;
}

