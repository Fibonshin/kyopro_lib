#include "header.hpp"
//誤差なしsqrt x<= INT_MAX

ll isqrt(ll x){
    ll ac=0,wa=1LL<<31;
    while(ac+1 < wa){
        ll m = (ac+wa)/2;
        if(m*m <=x)ac = m;
        else wa = m;
    }
    return ac;
}

