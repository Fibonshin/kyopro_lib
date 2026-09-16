#include "../header.cpp"

template <typename T>
struct V{
	T x,y;
	V():x(0),y(0){}
	template<typename A,typename B> V(A x, B y):x(x),y(y){}
	template<typename A,typename B> V(pair<A,B> p):x(p.first),y(p.second){}
	template <typename U> V(V<U> p) : x(p.x), y(p.y){}
	V& operator+=(const V& v) {x+=v.x;y+=v.y; return *this;}
	V operator+(const V& v) const {return V(*this)+=v;}
	V& operator-=(const V& v) {x-=v.x;y-=v.y; return *this;}
	V operator-(const V& v) const {return V(*this)-=v;}
	V& operator*=(T s) {x*=s;y*=s;return *this;}
	V operator*(T s) const {return V(*this)*=s;}
	V& operator/=(T s) {x/=s;y/=s; return *this;}
	V operator/(T s) const {return V(*this)/=s;}
	T dot(const V& v) const {return x*v.x+y*v.y;}
	T cross(const V& v) const {return x*v.y-v.x*y;}
	T norm2() const {return x*x + y*y;}
	double norm() const {return sqrt(norm2());}
	V normalize() const {return *this/norm();}
	V rotate90() const {return V(y, -x);}
};
template <typename T>
istream& operator>>(istream& is,V<T>& v) {
  is>>v.x>>v.y; return is;
}
template <typename T>
ostream& operator<<(ostream& os,const V<T>& v) {
  os<<v.x<<' '<<v.y; return os;
}

