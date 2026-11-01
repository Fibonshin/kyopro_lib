//メモリ制約が厳しいときに便利 https://judge.yosupo.jp/submission/413659
#include "header.hpp"

vector<int> erathosthenes(int n){
	vector<bool> f(n+1);
	for(int i=2;i*i<=n;i++)if(!f[i]){
		for(int j=i*i;j<=n;j+=i)f[j]=1;
	}
	vector<int> primes;
	for(int i=2;i<=n;i++)if(!f[i])primes.push_back(i);
	return primes;
}
