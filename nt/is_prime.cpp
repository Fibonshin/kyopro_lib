#include "header.hpp"

//素数判定 O(√N)
bool is_prime(ll x){
    if(x<=1)return 0;
	if(x%2==0)return 0;
    for(ll i=3;i*i<=x;i+=2)if(x%i==0)return 0;
    return 1;
}

