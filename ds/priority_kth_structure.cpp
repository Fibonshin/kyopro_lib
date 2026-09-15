#include "../header.cpp"

// 更新ありでK番目に大きなor小さな要素を取得。
// https://atcoder.jp/contests/abc475/submissions/79275764
template<class t,class Compare,class RCompare>struct PriorityKthStructure{
    ll k;
    priority_queue<t,vector<t>,RCompare> in,d_in;
    priority_queue<t,vector<t>,Compare> out,d_out;
    PriorityKthStructure(int _k):k(_k){};
	PriorityKthStructure(vector<t> v,int _k):k(_k){
		sort(v.rbegin(),v.rend(),Compare());
		rep(i,v.size()){
			if(i<k)in.push(v[i]);
			else out.push(v[i]);
		}
	}
    
    void insert(t x){
		in.push(x);
		if(in.size() > k+d_in.size()){
			out.push(in.top());
			in.pop();
			while(!in.empty() && !d_in.empty() && in.top()==d_in.top()){
				in.pop();
				d_in.pop();
			}
		}
    }
	// ないやつ与えられたらバグる
    void erase(t x){
		if(!in.empty() && in.top()==x)in.pop();
		else if(!in.empty() && Compare()(x,in.top()))d_out.push(x);
		else d_in.push(x);

		while(!out.empty() && !d_out.empty() && out.top()==d_out.top()){
			out.pop();
			d_out.pop();
		}
		if(in.size() < k+d_in.size() && !out.empty()){
			in.push(out.top());
			out.pop();
		}
    }

	t get_kth(){
		assert(in.size()==k+d_in.size());
		return in.top();
	}
};
template<typename T>
using MaxK = PriorityKthStructure<T,less<T>,greater<T>>;
template<typename T>
using MinK = PriorityKthStructure<T,greater<T>,less<T>>;
