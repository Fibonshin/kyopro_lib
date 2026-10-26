// https://judge.yosupo.jp/submission/413406
// https://judge.yosupo.jp/submission/413408
// ちょっと改変すると、異なる半環も渡せる(C++20)
// わざわざ半環作って渡すより、ライブラリ自体を抽象化したものを用意するほうがいい。
// https://atcoder.jp/contests/abc445/submissions/80403300
#include "header.hpp"

template<typename T> struct mat{
	static mat e(int n){
		mat res(n,n);
		rep(i,n)res[i][i]=1;
		return res;
	}
	int n,m;
	vector<vector<T>> dat;
	mat():n(0),m(0){}
	mat(int _n,int _m,T val=T()):n(_n),m(_m){
		dat.assign(n,vector<T>(m,val));
	}
	mat(const vector<vector<T>>& v){
		n=v.size();
		rep(i,n-1)assert(v[i].size()==v[i+1].size());
		m=(n?v[0].size():0);
		dat=v;
	}
	vector<T>& operator[](int i){return dat[i];}
	const vector<T>& operator[](int i)const{return dat[i];}
	mat& operator+=(const mat& a){
		assert(n==a.n && m==a.m);
		rep(i,n)rep(j,m)dat[i][j]+=a[i][j];
		return *this;
	}
	mat operator+(const mat& a) const {return mat(*this)+=a;}
	mat& operator-=(const mat& a){
		assert(n==a.n && m==a.m);
		rep(i,n)rep(j,m)dat[i][j]-=a[i][j];
		return *this;
	}
	mat operator-(const mat& a) const {return mat(*this)-=a;}
	mat operator*(const mat& a) const {
		assert(m==a.n);
		mat res(n,a.m);
		rep(i,n)rep(j,a.m)rep(k,m)res[i][j]+=dat[i][k]*a[k][j];
		return res;
	}
	mat& operator*=(const mat& a){return *this=*this*a;}
	mat& operator*=(T s){
		rep(i,n)rep(j,m)dat[i][j]*=s;
		return *this;
	}
	mat operator*(T s) const {return mat(*this)*=s;}
	mat& operator/=(T s){
		rep(i,n)rep(j,m)dat[i][j]/=s;
		return *this;
	}
	mat operator/(T s) const {return mat(*this)/=s;}
	mat pow(ll k) const{
		assert(n==m);
		mat res=e(n);
		mat a=*this;
		while(k){
			if(k&1)res*=a;
			a*=a;
			k>>=1;
		}
		return res;
	}
};
template<typename T>
istream& operator>>(istream& is,mat<T>& a) {
	rep(i,a.n)rep(j,a.m)is>>a[i][j];
	return is;
}
template <typename T>
ostream& operator<<(ostream& os,const mat<T>& a) {
	os<<a.dat;
	return os;
}
