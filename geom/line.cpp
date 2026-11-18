#include "header.hpp"
// 2点を通る直線の一般形ax+by+c
// gcdによりO(logN)

tuple<ll,ll,ll> line(V<ll> p,V<ll> q){
	assert(p.x!=q.x || p.y!=q.y);
	ll a=q.y-p.y;
	ll b=-(q.x-p.x);
	ll c=-(a*p.x+b*p.y);
	if(a<0)a=-a,b=-b,c=-c;
	if(a==0 && b<0)b=-b,c=-c;
	ll g=gcd(gcd(a,b),c);
	a/=g,b/=g,c/=g;
	return {a,b,c};
}

