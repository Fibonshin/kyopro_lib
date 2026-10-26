// https://judge.yosupo.jp/submission/413406
// https://judge.yosupo.jp/submission/413408
#include "header.hpp"

template<typename T> struct Matrix{
	static Matrix e(int n){
		Matrix res(n,n);
		rep(i,n)res[i][i]=1;
		return res;
	}
	int n,m;
	vector<vector<T>> dat;
	Matrix():n(0),m(0){}
	Matrix(int _n,int _m,T val=T()):n(_n),m(_m){
		dat.assign(n,vector<T>(m,val));
	}
	Matrix(const vector<vector<T>>& v){
		n=v.size();
		rep(i,n-1)assert(v[i].size()==v[i+1].size());
		m=(n?v[0].size():0);
		dat=v;
	}
	vector<T>& operator[](int i){return dat[i];}
	const vector<T>& operator[](int i)const{return dat[i];}
	Matrix& operator+=(const Matrix& a){
		assert(n==a.n && m==a.m);
		rep(i,n)rep(j,m)dat[i][j]+=a[i][j];
		return *this;
	}
	Matrix operator+(const Matrix& a) const {return Matrix(*this)+=a;}
	Matrix& operator-=(const Matrix& a){
		assert(n==a.n && m==a.m);
		rep(i,n)rep(j,m)dat[i][j]-=a[i][j];
		return *this;
	}
	Matrix operator-(const Matrix& a) const {return Matrix(*this)-=a;}
	Matrix operator*(const Matrix& a) const {
		assert(m==a.n);
		Matrix res(n,a.m);
		rep(i,n)rep(j,a.m)rep(k,m)res[i][j]+=dat[i][k]*a[k][j];
		return res;
	}
	Matrix& operator*=(const Matrix& a){return *this=*this*a;}
	Matrix& operator*=(T s){
		rep(i,n)rep(j,m)dat[i][j]*=s;
		return *this;
	}
	Matrix operator*(T s) const {return Matrix(*this)*=s;}
	Matrix& operator/=(T s){
		rep(i,n)rep(j,m)dat[i][j]/=s;
		return *this;
	}
	Matrix operator/(T s) const {return Matrix(*this)/=s;}
	Matrix pow(ll k) const{
		assert(n==m);
		Matrix res=e(n);
		Matrix a=*this;
		while(k){
			if(k&1)res*=a;
			a*=a;
			k>>=1;
		}
		return res;
	}
};
template<typename T>
istream& operator>>(istream& is,Matrix<T>& a) {
	rep(i,a.n)rep(j,a.m)is>>a[i][j];
	return is;
}
template <typename T>
ostream& operator<<(ostream& os,const Matrix<T>& a) {
	os<<a.dat;
	return os;
}
