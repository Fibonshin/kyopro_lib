#include "../header.cpp"

// 配列の余白をカット
vector<string> trim(vector<string>&x,char nop){
	int l=x[0].size(),r=0,u=x.size(),d=0;
	rep(i,x.size())rep(j,x[0].size()){
		if(x[i][j]!=nop){
			chmin(l,j);chmin(u,i);
			chmax(r,j);chmax(d,i);
		}
	}
	vector res=vector(x.begin()+u,x.begin()+d+1);
	for(string&i:res)i=string(i.begin()+l,i.begin()+r+1);
	return res;
};

template<typename T>vector<vector<T>> trim(vector<vector<T>>&x,char nop){
	int l=x[0].size(),r=0,u=x.size(),d=0;
	rep(i,x.size())rep(j,x[0].size()){
		if(x[i][j]!=nop){
			chmin(l,j);chmin(u,i);
			chmax(r,j);chmax(d,i);
		}
	}
	vector res=vector(x.begin()+u,x.begin()+d+1);
	for(vector<T>&i:res)i=vector(i.begin()+l,i.begin()+r+1);
	return res;
};
