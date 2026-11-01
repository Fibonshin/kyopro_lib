// https://atcoder.jp/contests/abc419/submissions/80452317
// https://atcoder.jp/contests/abc268/submissions/80452341
#include "header.hpp"

struct AhoCorasick{
	bool built=0;
	struct node{
		int cnt=0;
		int failure=0;
		unordered_map<char,int> to;
		vector<int> ids;
	};
	vector<node> nodes;
	vector<int> states;
	AhoCorasick():nodes(1){}
	int insert(const string&s){
		built=0;
		int v=0;
		for(char c:s){
			if(!nodes[v].to.count(c)){
				nodes[v].to[c]=nodes.size();
				nodes.emplace_back();
			}
			v=nodes[v].to[c];
		}
		nodes[v].cnt++;
		nodes[v].ids.push_back(states.size());
		states.push_back(v);
		return v;
	}
	void build(){
		built=1;
		queue<int> qu;
		qu.push(0);
		while(!qu.empty()){
			int u=qu.front();
			qu.pop();
			for(auto[c,v]:nodes[u].to){
				nodes[v].failure=u==0?0:next(nodes[u].failure,c);
				nodes[v].cnt+=nodes[nodes[v].failure].cnt;
				qu.push(v);
			}
		}
	}
	int next(int v,char c){
		assert(built);
		assert(0<=v && v<nodes.size());
		while(1){
			if(nodes[v].to.count(c))return nodes[v].to[c];
			if(v==0)return 0;
			v=nodes[v].failure;
		}
	}
	int count(int v){
		assert(built);
		assert(0<=v && v<nodes.size());
		return nodes[v].cnt;
	}
	int size(){
		assert(built);
		return nodes.size();
	}
	int state(int id){
		assert(0<=id && id<states.size());
		return states[id];
	}
	vector<int> matches(int v){
		assert(built);
		assert(0<=v && v<nodes.size());
		vector<int> res;
		while(1){
			for(int id:nodes[v].ids)res.push_back(id);
			if(!v)break;
			v=nodes[v].failure;
		};
		return res;
	}
};

