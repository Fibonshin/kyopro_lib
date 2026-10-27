// https://atcoder.jp/contests/abc445/submissions/80433729
#include "header.hpp"

struct Sieve{
	int n;
	vector<int> primes,spf;
	Sieve():n(0){}
	Sieve(int _n):n(_n){
		spf.resize(n+1);
		for(int i=2;i<=n;i++){
			if(spf[i]==0){
				spf[i]=i;
				primes.push_back(i);
			}
			for(int p:primes){
				if(p>spf[i])break;
				if(i*p>n)break;
				spf[i*p]=p;
			}
		}
	}
	bool is_prime(int x){
		assert(x<=n);
		return x>=2&&spf[x]==x;
	}
	vector<pair<int,int>> factors(int x){
		assert(x<=n);
		vector<pair<int,int>> res;
		while(x>1){
			int p=spf[x];
			if(!res.empty() && res.back().first==p)res.back().second++;
			else res.emplace_back(p,1);
			x/=p;
		}
		return res;
	}
};
