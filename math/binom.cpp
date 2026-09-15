#include "../header.cpp"

//nCr 前計算O(n) クエリO(1) 何回も計算するときに。
mint binom(int n,int r){
	if(n < 0 || r < 0 || n < r)
		return 0;

	static vector<mint> fact={1};
	static vector<mint> invf={mint(1).inv()};

	while(fact.size() <= n)
	{
		fact.push_back(fact.back() * fact.size());
		invf.push_back(fact.back().inv());
	}
	return fact[n] * invf[r] * invf[n-r];
}

//nCr O(r) Nがデカいときに。
mint binom(ll n,int r){
	if(n < 0 || r < 0 || n < r)
		return 0;
	mint res=1;
	rep(i,r){
		res*=n-i;
		res/=r-i;
	}
	return res;
}
