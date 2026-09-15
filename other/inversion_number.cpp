#include "../header.cpp"

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

