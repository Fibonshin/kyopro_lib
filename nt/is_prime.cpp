#include "../header.cpp"

//素数判定 O(√N)
bool is_prime(ll x){
    if(x<=1)return 0;
    for(ll i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}

