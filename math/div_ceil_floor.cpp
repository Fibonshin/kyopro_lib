#include "../header.cpp"

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
