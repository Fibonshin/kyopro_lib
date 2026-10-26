//minplus半環 https://atcoder.jp/contests/abc445/submissions/80404789
//ふつーの環 https://judge.yosupo.jp/submission/413424
#include "header.hpp"

// デフォルトはmin-plus半環
template<typename T> struct Semiring{
	static T add(T a, T b){return min(a,b);}
	static T mul(T a, T b){return min(a+b,inf);}
	static T one(){return 0;}
	static T zero(){return inf;}
};
template<typename T,typename Semiring=Semiring<T>> struct SemiringMatrix{
	static SemiringMatrix e(int n){
		SemiringMatrix res(n,n);
		rep(i,n)res[i][i]=Semiring::one();
		return res;
	}
	int n,m;
	vector<vector<T>> dat;
	SemiringMatrix():n(0),m(0){}
	SemiringMatrix(int _n,int _m,T val=Semiring::zero()):n(_n),m(_m){
		dat.assign(n,vector<T>(m,val));
	}
	SemiringMatrix(const vector<vector<T>>& v){
		n=v.size();
		rep(i,n-1)assert(v[i].size()==v[i+1].size());
		m=(n?v[0].size():0);
		dat=v;
	}
	vector<T>& operator[](int i){return dat[i];}
	const vector<T>& operator[](int i)const{return dat[i];}
	SemiringMatrix& operator+=(const SemiringMatrix& a){
		assert(n==a.n && m==a.m);
		rep(i,n)rep(j,m)dat[i][j]=Semiring::add(dat[i][j],a[i][j]);
		return *this;
	}
	SemiringMatrix operator+(const SemiringMatrix& a) const {return SemiringMatrix(*this)+=a;}
	SemiringMatrix operator*(const SemiringMatrix& a) const {
		assert(m==a.n);
		SemiringMatrix res(n,a.m);
		rep(i,n)rep(j,a.m)rep(k,m)res[i][j]=Semiring::add(res[i][j],Semiring::mul(dat[i][k],a[k][j]));
		return res;
	}
	SemiringMatrix& operator*=(const SemiringMatrix& a){return *this=*this*a;}
	SemiringMatrix& operator*=(T s){
		rep(i,n)rep(j,m)dat[i][j]=Semiring::mul(dat[i][j],s);
		return *this;
	}
	SemiringMatrix operator*(T s) const {return SemiringMatrix(*this)*=s;}
	SemiringMatrix pow(ll k) const{
		assert(n==m);
		SemiringMatrix res=e(n);
		SemiringMatrix a=*this;
		while(k){
			if(k&1)res*=a;
			a*=a;
			k>>=1;
		}
		return res;
	}
};
template<typename T>
istream& operator>>(istream& is,SemiringMatrix<T>& a) {
	rep(i,a.n)rep(j,a.m)is>>a[i][j];
	return is;
}
template <typename T>
ostream& operator<<(ostream& os,const SemiringMatrix<T>& a) {
	os<<a.dat;
	return os;
}
