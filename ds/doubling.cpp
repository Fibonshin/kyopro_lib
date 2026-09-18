#include "../header.cpp"

// https://atcoder.jp/contests/abc167/submissions/79328628
// https://atcoder.jp/contests/tessoku-book/submissions/79328843
// https://atcoder.jp/contests/tessoku-book/submissions/79329314
struct Doubling{
	vector<int> p;
	int n;
	vector<vector<int>> dp;
	int log=64;
	Doubling(vector<int> p_):p(p_){
		n=p.size();
		dp.assign(log,vector<int>(n));
		rep(j,n)dp[0][j]=p[j];
		rep(i,log-1)rep(j,n){
			dp[i+1][j]=dp[i][dp[i][j]];
		}
	}
	int jump(int x,unsigned long long k){
		int res=x;
		rep(i,log)if(k&1LL<<i){
			res=dp[i][res];
		}
		return res;
	}
};
