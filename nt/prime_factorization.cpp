#include "../header.cpp"

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
