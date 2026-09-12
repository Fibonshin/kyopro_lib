#include "header.cpp"
 
/*
prime numbers
vector<int> primes={
    1000000007,
    1000000009,
    1000000021,
    1000000033,
    1000000087,
    1000000093,
    1000000097,
    1000000103,
    1000000123,
    1000000181,
    1000000207,
    1000000223,
    1000000241,
    1000000271,
    1000000289,
    1000000297,
    1000000321,
    1000000349,
    1000000363,
    1000000403,
    1000000409,
    1000000411,
    1000000427,
    1000000433,
    1000000439,
    1000000447,
    1000000453,
    1000000459,
    1000000483
};

1e16+61
*/

//素因数列挙 O(√N)
vector<pair<ll,ll>> prime_factorization(ll x){
    vector<pair<ll,ll>> res;
    for(ll i=2;i<=sqrt(x);i++){
        if(x%i==0){
            res.emplace_back(i,1LL);
            x/=i;
        }
        while (x%i==0)
        {
            res.back().second++;
            x/=i;
        }
    }
    if(x!=1)res.emplace_back(x,1);
    return res;
}

// n以下のすべての非負整数の素因数列挙 O(NlogN)?
// 0,1は空
vector<vector<pair<ll,ll>>> pf_all(int n){
    vector<vector<pair<ll,ll>>> res(n+1);
    for(int i=2;i<=n;i++){
        if(!res[i].empty())continue;
        for(int j=i;j<=n;j+=i){
            res[j].emplace_back(i,1);
            for(int mj=j;(mj/=i)%i==0;)res[j].back().second++;
        }
    }
    return res;
}

//約数列挙 O(√N)
vector<ll> enumdiv(ll n) { 
    vector<ll> res;
    for (ll i = 1; i <= sqrt(n); i++) if (n%i == 0) { res.push_back(i); if (i != sqrt(n)) res.push_back(n / i); }
    sort(res.begin(), res.end());
    return res;
}

//素数判定 O(√N)
bool is_prime(ll x){
    if(x<=1)return 0;
    for(ll i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}

// エラトステネスの篩 O(NloglogN)
vector<int> eratosthenes(int x){
    vector<bool> deleted(x+1);
    for(int i=2;i<=sqrt(x);i++){
        if(deleted[i])continue;
        for(int j=i*2;j<=x;j+=i)deleted[j]=1;
    }
    vector<int> res;
    for(int i=2;i<=x;i++)if(!deleted[i])res.push_back(i);
    return res;
}

//拡張ユークリッド ax+by=gcd(a,b)の(x,y)
// verify at https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=8933684#1
pair<ll,ll> extgcd(ll a,ll b){
    if(b==0)return {1,0};
    ll q=a/b,r=a%b;
    auto[x,y]=extgcd(b,r);
    return {y,x-q*y};
}

// 分数の比較 a/b
struct frac{
    ll a,b;
    frac(ll _a=0,ll _b=1): a(_a),b(_b){
        if(b==0){a=1;return;}
        if(b < 0)a=-a,b=-b;
        ll g=gcd(a,b);
        a/=g,b/=g;
    }
    bool operator<(const frac& x) const{
        return a*x.b < x.a*b;
    }
    bool operator<=(const frac& x) const{
        return a*x.b <= x.a*b;
    }
    bool operator==(const frac& x) const{
        return a*x.b == x.a*b;
    }
    bool operator!=(const frac& x) const{
        return a*x.b != x.a*b;
    }
};

//nCr 前計算O(n) クエリO(1) 何回も計算するときに。
mint comb(int n,int r){
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
mint comb(ll n,int r){
	if(n < 0 || r < 0 || n < r)
		return 0;
	mint res=1;
	rep(i,r){
		res*=n-i;
		res/=r-i;
	}
	return res;
}

//複数modでの計算
const int p1=1000000349;
const int p2=1000000103;
struct mints {
  int d1, d2;
  mints(int val=0): d1(val), d2(val) {}
  mints(int d1, int d2): d1(d1), d2(d2) {}
  mints operator+(const mints& a) const {
    return mints((d1+a.d1)%p1, (d2+a.d2)%p2);
  }
  mints operator*(const mints& a) const {
    return mints(((ll)d1*a.d1)%p1, ((ll)d2*a.d2)%p2);
  }
  bool operator==(const mints& a) const {
    return d1 == a.d1 && d2 == a.d2;
  }
};

//誤差なしsqrt
ll isqrt(ll x){
    ll ac=0,wa=1e9+1;
    while(ac+1 < wa){
        ll m = (ac+wa)/2;
        if(m <= 1e9 && m*m <=x)ac = m;
        else wa = m;
    }
    return ac;
}

// a/b 床関数
ll div_floor(ll a,ll b){
	if(b<0)a=-a,b=-b;
	if(a<0)return (a-b+1)/b;
	return a/b;
}

// a/b 天井関数
ll div_ceil(ll a,ll b){
	if(b<0)a=-a,b=-b;
	if(a<0)return a/b;
	return (a+b-1)/b;
}
